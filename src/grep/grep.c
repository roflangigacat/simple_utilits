#include "grep.h"

int main(int argc, char **argv) {
  char opts[2][4096];
  char *short_options = "ivclnhsof:e:";
  char flags[] = "\0\0\0";
  int result = getopt(argc, argv, short_options);
  if (result != -1 && result != '?') {
    flags[0] = result;
    if (flags[0] == 'e' || flags[0] == 'f') {
      strcpy(opts[0], optarg);
    }
    result = getopt(argc, argv, short_options);
    if (result != -1 && result != '?') {
      flags[1] = result;
      if (flags[1] == 'e' || flags[1] == 'f') {
        strcpy(opts[1], optarg);
      }
    }
  }
  argc -= optind;
  argv += optind;
  if (argc > 0 && result != '?') {
    scanfile(argc, argv, flags, opts);
  }
}
void scanfile(int argc, char **argv, char *flags, char opts[][4096]) {
  int color_check = system("test -t 1");
  CREATE_COLOR_ARRAY(color_check);
  regex_t stepan;
  regmatch_t sava;
  int check = 0;
  if (argc == 0) {
    fprintf(stderr, "grep: enter string and filename to search");
  } else {
    if (!strchr(flags, 'e') && !strchr(flags, 'f')) {
      stepan = compileregnoarg(argv, flags);
      argc--;
      argv++;
    } else if (strchr(flags, 'e') || strchr(flags, 'f')) {
      if (strchr(flags, 'e')) {
        if (strchr(flags, 'e') == flags) {
          stepan = compileregE(opts[0], flags[1]);
        } else {
          stepan = compileregE(opts[1], flags[0]);
        }
      }
      if (strchr(flags, 'f')) {
        if (strchr(flags, 'f') == flags) {
          stepan = compileargF(opts[0], &check, flags);
        } else {
          stepan = compileargF(opts[1], &check, flags);
        }
      }
    } else {
      fprintf(stderr, "grep: no file specified\n");
    }
    if (check == 0) {
      for (int i = 0; i < argc; i++) {
        FILE *f;
        f = fopen(argv[i], "r");
        if (f == NULL) {
          if (!strchr(flags, 's'))
            fprintf(stderr, "grep %s: no such file or directory\n", argv[i]);
        } else {
          int status = -1;
          int count1 = 0;
          int count = 0;
          while (!feof(f)) {
            char *buff = calloc(4096, sizeof(char));
            fscanf(f, "%4095[^\n]s", buff);
            getc(f);
            buff[strlen(buff) + 1] = '\0';
            buff[strlen(buff)] = '\n';
            if (buff[strlen(buff) - 1] == '\n' && !strchr(flags, 'v')) {
              buff[strlen(buff) - 1] = '\0';
            }
            count++;
            int compare = 0;
            status = regexec(&stepan, buff, 1, &sava, REG_NOTBOL);
            if (((status == 0 && !strchr(flags, 'v')) ||
                 ((strchr(flags, 'v') && status != compare) &&
                  strlen(buff) != 0 && !(buff[0] == '\n' && feof(f))))) {
              if (count1 != 0 && !strchr(flags, 'o') && !strchr(flags, 'l') &&
                  !strchr(flags, 'c') && !strchr(flags, 'v')) {
                printf("\n");
              }
              count1++;
              if (strchr(flags, 'o')) {
                compare = 1;
              }
              if (argc > 1 && !(strchr(flags, 'l')) && !(strchr(flags, 'h')) &&
                  !(strchr(flags, 'c')) && (PRINTFILE || !compare)) {
                printf("%s%s%s%s:%s", CPURPLE, argv[i], CRESET, CBLUE, CRESET);
              }
              if (strchr(flags, 'n') && !strchr(flags, 'l') &&
                  !(strchr(flags, 'c')) && (PRINTFILE || !compare)) {
                printf("%s%d%s%s:%s", CGREEN, count, CRESET, CBLUE, CRESET);
              }
              if (!strchr(flags, 'l') && !strchr(flags, 'c')) {
                if (strchr(flags, 'o') && !strchr(flags, 'v')) {
                  char *stroka = buff;
                  int linecount = 0;
                  while (status == 0) {
                    if (linecount++ != 0) {
                      printf("\n");
                    }
                    if (!PRINTFILE) {
                      printf("%s%s%s%s:%s", CPURPLE, argv[i], CRESET, CBLUE,
                             CRESET);
                    }
                    if (!PRINTFILE && strchr(flags, 'n')) {
                      printf("%s%d%s%s:%s", CGREEN, count, CRESET, CBLUE,
                             CRESET);
                    }
                    printf("%s%.*s%s", CRED, (int)(sava.rm_eo - sava.rm_so),
                           stroka + sava.rm_so, CRESET);
                    status = regexec(&stepan, stroka += sava.rm_eo, 1, &sava,
                                     REG_NOTBOL);
                  }
                  printf("\n");
                } else {
                  printf("%s", buff);
                }
              } else if (!(strchr(flags, 'c'))) {
                free(buff);
                break;
              }
            }
            free(buff);
          }
          if (((((status == 0 || (status == 1 && strchr(flags, 'v'))) &&
                 strchr(flags, 'l')) ||
                (strchr(flags, 'c') && argc > 1)) &&
               !strchr(flags, 'h')) ||
              (strchr(flags, 'h') && strchr(flags, 'l'))) {
            printf("%s%s%s", CPURPLE, argv[i], CRESET);
          }
          if (strchr(flags, 'c')) {
            if (argc > 1 && !strchr(flags, 'h')) {
              printf("%s:%s", CBLUE, CRESET);
            }
            printf("%d", count1);
          }
          if ((!strchr(flags, 'v') && !strchr(flags, 'o')) ||
              strchr(flags, 'c') ||
              (strchr(flags, 'v') && strchr(flags, 'l')) ||
              (strchr(flags, 'l') && strchr(flags, 'o'))) {
            printf("\n");
          }
        }
      }
      regfree(&stepan);
    }
  }
}
regex_t compileregE(char *str, char flag) {
  regex_t result;
  char qwe[4096];
  strcpy(qwe, str);
  if (flag == 'i') {
    regcomp(&result, qwe, REG_ICASE);
  } else {
    regcomp(&result, qwe, 0);
  }
  return result;
}
regex_t compileregnoarg(char **argv, char *flags) {
  regex_t result;
  char qwe[4096];
  strcpy(qwe, argv[0]);
  if (strchr(flags, 'i')) {
    regcomp(&result, qwe, REG_ICASE);
  } else {
    regcomp(&result, qwe, 0);
  }
  return result;
}
regex_t compileargF(char *str, int *flag, char *flags) {
  regex_t result;
  char *qwe = calloc(4096, sizeof(char));
  char *zxc = calloc(4096, sizeof(char));
  FILE *file = fopen(str, "r");
  if (file == NULL) {
    regcomp(&result, "\0", 0);
    *flag = 1;
    fprintf(stderr, "grep %s: no such file or directory\n", str);
  } else {
    int flaggg = REG_EXTENDED | REG_NEWLINE;
    if (strchr(flags, 'i')) flaggg |= REG_ICASE;
    while (!feof(file)) {
      fscanf(file, "%4095[^\n]s", zxc);
      getc(file);
      strcat(qwe, zxc);
      if (!(feof(file))) {
        strcat(qwe, "|");
      }
    }
    fclose(file);
    regcomp(&result, qwe, flaggg);
  }
  free(qwe);
  free(zxc);
  return result;
}
