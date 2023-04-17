#ifndef SRC_GREP_GREP_H_
#define SRC_GREP_GREP_H_

#include <getopt.h>
#include <math.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if __APPLE__
#define PRINTFILE 1
#elif __linux__
#define PRINTFILE 0
#endif

enum colors { RED, GREEN, BLUE, PURPLE, RESET };

#define CREATE_COLOR_ARRAY(color_check)          \
  char *colors_arr[15] = {"", "", "", "", ""}; \
  if (!color_check) {                            \
    colors_arr[RED] = "\e[31;1m";                \
    colors_arr[GREEN] = "\e[32;1m";              \
    colors_arr[BLUE] = "\e[36;1m";               \
    colors_arr[PURPLE] = "\e[35;1m";             \
    colors_arr[RESET] = "\e[0m";                 \
  }

#define CRED colors_arr[RED]
#define CGREEN colors_arr[GREEN]
#define CPURPLE colors_arr[PURPLE]
#define CBLUE colors_arr[BLUE]
#define CRESET colors_arr[RESET]

void scanfile(int argc, char **argv, char *flags, char opts[][4096]);
regex_t compileregE(char *str, char flag);
regex_t compileregnoarg(char **argv, char *flags);
regex_t compileargF(char *str, int *flag, char *flags);

#endif  // SRC_GREP_GREP_H_
