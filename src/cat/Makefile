CC = gcc -std=c11
CFLAGS = -Wall -Werror -Wextra
CAT_FILES = s21_cat.c
CAT_OBJ = $(CAT_FILES:.c=.o)
CAT_EXEC = ./s21_cat
TESTS = tests/

OS = $(shell uname)
ifeq ($(OS), Darwin)
LEAK_CHECK =
endif
ifeq ($(OS), Linux)
LEAK_CHECK = valgrind --leak-check=full -s -q 
endif

all: build

build: s21_cat

rebuild: clean build

s21_cat:
	$(CC) $(CFLAGS) $(CAT_FILES) -o $(CAT_EXEC)

check: clean s21_cat_test

s21_cat_test:
	($(LEAK_CHECK)$(CAT_EXEC) Makefile cat_test_file.txt ../../README.md > $(TESTS)s21_cat_test.txt)
	cat Makefile cat_test_file.txt ../../README.md > $(TESTS)cat_test.txt
	($(LEAK_CHECK)$(CAT_EXEC) -b Makefile cat_test_file.txt ../../README.md > $(TESTS)s21_cat_test_b.txt)
	cat -b Makefile cat_test_file.txt ../../README.md > $(TESTS)cat_test_b.txt
	($(LEAK_CHECK)$(CAT_EXEC) -e Makefile cat_test_file.txt ../../README.md > $(TESTS)s21_cat_test_e.txt)
	cat -e Makefile cat_test_file.txt ../../README.md > $(TESTS)cat_test_e.txt
	($(LEAK_CHECK)$(CAT_EXEC) -n Makefile cat_test_file.txt > $(TESTS)s21_cat_test_n.txt && cat -n Makefile cat_test_file.txt > $(TESTS)cat_test_n.txt)	
	($(LEAK_CHECK)$(CAT_EXEC) -s Makefile cat_test_file.txt ../../README.md > $(TESTS)s21_cat_test_s.txt)
	cat -s Makefile cat_test_file.txt ../../README.md > $(TESTS)cat_test_s.txt
	($(LEAK_CHECK)$(CAT_EXEC) -t Makefile cat_test_file.txt ../../README.md > $(TESTS)s21_cat_test_t.txt)
	cat -t Makefile cat_test_file.txt ../../README.md > $(TESTS)cat_test_t.txt
	($(LEAK_CHECK)$(CAT_EXEC) -v Makefile cat_test_file.txt ../../README.md > $(TESTS)s21_cat_test_v.txt)
	cat -v Makefile cat_test_file.txt ../../README.md > $(TESTS)cat_test_v.txt
ifeq ($(OS), Linux)
	($(LEAK_CHECK)$(CAT_EXEC) -E Makefile cat_test_file.txt ../../README.md > $(TESTS)s21_cat_test_E.txt)
	cat -E Makefile cat_test_file.txt ../../README.md > $(TESTS)cat_test_E.txt
	($(LEAK_CHECK)$(CAT_EXEC) -T Makefile cat_test_file.txt ../../README.md > $(TESTS)s21_cat_test_T.txt)
	cat -T Makefile cat_test_file.txt ../../README.md > $(TESTS)cat_test_T.txt
	($(LEAK_CHECK)$(CAT_EXEC) --number-nonblank Makefile cat_test_file.txt ../../README.md > $(TESTS)s21_cat_test_number_nonblank.txt)
	cat --number-nonblank Makefile cat_test_file.txt ../../README.md > $(TESTS)cat_test_number_nonblank.txt
	($(LEAK_CHECK)$(CAT_EXEC) --number Makefile cat_test_file.txt ../../README.md > $(TESTS)s21_cat_test_number.txt)
	cat --number Makefile cat_test_file.txt ../../README.md > $(TESTS)cat_test_number.txt
	($(LEAK_CHECK)$(CAT_EXEC) --squeeze-blank Makefile cat_test_file.txt ../../README.md > $(TESTS)s21_cat_test_squeeze-blank.txt)
	cat --squeeze-blank Makefile cat_test_file.txt ../../README.md > $(TESTS)cat_test_squeeze-blank.txt
	
endif
# File comparsions
	diff $(TESTS)s21_cat_test.txt $(TESTS)cat_test.txt
	diff $(TESTS)s21_cat_test_b.txt $(TESTS)cat_test_b.txt
	diff $(TESTS)s21_cat_test_e.txt $(TESTS)cat_test_e.txt
	diff $(TESTS)s21_cat_test_n.txt $(TESTS)cat_test_n.txt
	diff $(TESTS)s21_cat_test_s.txt $(TESTS)cat_test_s.txt
	diff $(TESTS)s21_cat_test_v.txt $(TESTS)cat_test_v.txt
ifeq ($(OS), Linux)
	diff $(TESTS)s21_cat_test_E.txt $(TESTS)cat_test_E.txt
	diff $(TESTS)s21_cat_test_T.txt $(TESTS)cat_test_T.txt
	diff $(TESTS)s21_cat_test_number_nonblank.txt $(TESTS)cat_test_number_nonblank.txt
	diff $(TESTS)s21_cat_test_number.txt $(TESTS)cat_test_number.txt
	diff $(TESTS)s21_cat_test_squeeze-blank.txt $(TESTS)cat_test_squeeze-blank.txt
endif

clean:
	rm -rf $(TESTS)*.txt
	rm -rf *.o *.gch
	rm -rf *.dSYM
	rm -rf $(COMMON_PATH)*.o
	rm -rf s21_cat
	rm -rf *.out