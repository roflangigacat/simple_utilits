#!/bin/bash

# Передаваемые переменные
leak_check="$1" # проверка на утечки (если linux)
grep_exec="$2"  # исполняемый файл
tests_path="$3" # папка с результатами тестов
pattern="$4"    # шаблон поиска
regex_file="$5" # файл с шаблонами
log_file="$6"   # файл лога с информацией об утечках

necessary_params_count=6

# Разбиение входных параметров
params=("$@")
files=""
params_count=0

for param in "${params[@]}"; do
  ((params_count++))
  if [[ params_count -ge $((necessary_params_count + 1)) ]]; then
    if [[ $((params_count - necessary_params_count + 1)) -ne 0 ]]; then
      files+=" "
    fi
    files+="${param}"
  fi
done

# Переменные для начала и конца команды
s21_start="(${leak_check}${grep_exec} "
s21_mid=" ${files} > ${tests_path}s21_grep_test_"
s21_end=".txt)"

start="grep "
mid=" ${files} > ${tests_path}grep_test_"
end=".txt"

# Переменные для цикла
flags=(e i v c l h n s f o)

# Подсчёт количества пройденных и проваленных тестов
tests_count=0
passed_tests=0

# Сравнение работы без флагов
command="${start}${pattern}${mid}no_flags${end}"
s21_command="${s21_start}${pattern}${s21_mid}no_flags${s21_end}"
compare_command="diff ${tests_path}grep_test_no_flags.txt ${tests_path}s21_grep_test_no_flags.txt"
((tests_count++))
eval "$command"
printf "Test %s: no flags\n" "$tests_count" >"$log_file"
leaks_err=$(eval "$s21_command" 2>>"$log_file")
printf "\n" >>"$log_file"
err_num=$(eval "$compare_command")
printf "\e[33;1mTest %s\e[0m\e[34;1m:\e[0m \e[36;1mno flags\e[0m \e[33;1m---\e[0m " "$tests_count"
if [[ $err_num || $leaks_err ]]; then
  printf "\e[31;1m%s\e[0m" "FAILED "
  if [[ $err_num ]]; then
    printf "\e[33;1m[\e[31;1moutput\e[0m\e[33;1m]\e[0m"
  fi
  if [[ $leaks_err ]]; then
    printf "\e[33;1m[\e[31;1leaks\e[0m\e[33;1m]\e[0m"
  fi
  printf "\n"
else
  ((passed_tests++))
  printf "\e[32;1m%s\e[0m\n" "PASSED"
fi

# Сравнение с одним флагом
for flag in "${flags[@]}"; do
  if [[ "$flag" = "e" ]]; then
    args="-e ${pattern}"
  elif [[ "$flag" = "f" ]]; then
    args="-f ${regex_file}"
  else
    args="-${flag} ${pattern}"
  fi
  command="${start}${args}${mid}${flag}${end}"
  s21_command="${s21_start}${args}${s21_mid}${flag}${s21_end}"
  compare_command="diff ${tests_path}grep_test_${flag}${end} ${tests_path}s21_grep_test_${flag}${end}"
  ((tests_count++))
  eval "$command"
  printf "Test %s: %s\n" "${args}" "$tests_count" >>"$log_file"
  leaks_err=$(eval "$s21_command" 2>>"$log_file")
  printf "\n" >>"$log_file"
  err_num=$(eval "$compare_command")
  printf "\e[33;1mTest %s\e[0m\e[34;1m:\e[0m \e[36;1m%s\e[0m \e[33;1m---\e[0m " "$tests_count" "${args}"
  if [[ $err_num || $leaks_err ]]; then
    printf "\e[31;1m%s\e[0m" "FAILED "
    if [[ $err_num ]]; then
      printf "\e[33;1m[\e[31;1moutput\e[0m\e[33;1m]\e[0m"
    fi
    if [[ $leaks_err ]]; then
      printf "\e[33;1m[\e[31;1leaks\e[0m\e[33;1m]\e[0m"
    fi
    printf "\n"
  else
    ((passed_tests++))
    printf "\e[32;1m%s\e[0m\n" "PASSED"
  fi
done

# Парные флаги
for first_flag in "${flags[@]}"; do
  for second_flag in "${flags[@]}"; do
    flags_comb=""
    short_flags_comb=""
    if [[ "$first_flag" != "$second_flag" ]]; then
      if [[ "$first_flag" = "e" ]]; then
        flags_comb+="-e ${pattern} "
        short_flags_comb+="e"
      elif [[ "$first_flag" = "f" ]]; then
        flags_comb+="-f ${regex_file} "
        short_flags_comb+="f"
      else
        flags_comb+="-${first_flag} "
        short_flags_comb+=${first_flag}
      fi
      if [[ "$second_flag" = "e" ]]; then
        flags_comb+="-e ${pattern}"
        short_flags_comb+="e"
      elif [[ "$second_flag" = "f" ]]; then
        flags_comb+="-f ${regex_file}"
        short_flags_comb+="f"
      else
        flags_comb+="-${second_flag}"
        if [[ "$first_flag" != "e" && "$first_flag" != "f" ]]; then
          flags_comb+=" ${pattern}"
        fi
        short_flags_comb+=${second_flag}
      fi
    fi
    if [[ "$first_flag" != "$second_flag" ]]; then
      command="${start}${flags_comb}${mid}${short_flags_comb}${end}"
      s21_command="${s21_start}${flags_comb}${s21_mid}${short_flags_comb}${s21_end}"
      compare_command="diff ${tests_path}grep_test_${short_flags_comb}${end} ${tests_path}s21_grep_test_${short_flags_comb}${end}"
      ((tests_count++))
      eval "$command"
      printf "Test %s: %s\n" "${flags_comb}" "$tests_count" >>"$log_file"
      leaks_err=$(eval "$s21_command" 2>>"$log_file")
      printf "\n" >>"$log_file"
      err_num=$(eval "$compare_command")
      printf "\e[33;1mTest %s\e[0m\e[34;1m:\e[0m \e[36;1m%s\e[0m \e[33;1m---\e[0m " "$tests_count" "${flags_comb}"
      if [[ $err_num || $leaks_err ]]; then
        printf "\e[31;1m%s\e[0m" "FAILED "
        if [[ $err_num ]]; then
          printf "\e[33;1m[\e[31;1moutput\e[0m\e[33;1m]\e[0m"
        fi
        if [[ $leaks_err ]]; then
          printf "\e[33;1m[\e[31;1leaks\e[0m\e[33;1m]\e[0m"
        fi
        printf "\n"
      else
        ((passed_tests++))
        printf "\e[32;1m%s\e[0m\n" "PASSED"
      fi
    fi
  done
done

# Сводка
printf "\e[33;1m----------------------------------------------\e[0m\n"
printf "\e[33;1mTOTAL\e[0m\e[34;1m:\e[0m \e[36;1m%s\e[0m\t\e[32;1mPASSED\e[0m\e[34;1m:\e[0m \e[36;1m%s\e[0m\t\e[31;1mFAILED\e[0m\e[34;1m:\e[0m \e[36;1m%s\e[0m\n" "$tests_count" "$passed_tests" "$((tests_count - passed_tests))"
if [[ $((tests_count - passed_tests)) ]]; then
  exit 1
else
  exit 0
fi
