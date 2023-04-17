#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_
#include <getopt.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#if __APPLE__
#define OPTS                            \
  const char *short_options = "bevnst"; \
  const struct option long_options[] = {{NULL, 0, NULL, 0}};
#elif __linux__
#define OPTS                                        \
  const char *short_options = "bevEnstT";           \
  const struct option long_options[] = {            \
      {"number-nonblank", no_argument, NULL, 'b'},  \
      {"number", no_argument, NULL, 'n'},           \
      {"squeeze-blank", no_argument, NULL, 's'},    \
      {"show-nonprinting", no_argument, NULL, 'v'}, \
      {NULL, 0, NULL, 0}};
#endif

// На маке новый файл - печатает с единицы, на линукс - продолжает счет строк
#if __APPLE__
#define NCASE(n) n = 0;
#elif __linux__
#define NCASE(n)
#endif

// обработка скрытых символов для линуха
#if __APPLE__
#define VCASE
#elif __linux__
#define VCASE                          \
  } else if (c >= 160 && c <= 254) {   \
    printf("M-%c", '!' - 1 + c - 160); \
  } else if (c == 255) {               \
    printf("M-^?");
#endif

void scanfile(int argc, char *argv[], int result);
void scanparam(int result, unsigned char c, int *flag);
void case_e(unsigned char c);
void case_b(unsigned char c, int *flag, int *strcount);
void case_E(unsigned char c);
void case_t(unsigned char c);
void case_T(unsigned char c);
void case_v(unsigned char c);
void case_s(unsigned char c, int *flag);
void case_n(unsigned char c, int *flag);

#endif  // SRC_CAT_S21_CAT_H_
