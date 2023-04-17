#include "s21_cat.h"
int main(int argc, char *argv[]) {
  OPTS;
  int result = getopt_long(argc, argv, short_options, long_options, NULL);
  if (argc > 1 && result != '?') {
    scanfile(argc, argv, result);
  }
}
void scanfile(int argc, char *argv[], int result) {
  unsigned char c;
  argc -= optind;
  argv += optind;
  for (int i = 0; i < argc; i++) {
    FILE *fp;
    if ((fp = fopen(argv[i], "r")) != NULL) {
      c = fgetc(fp);
      int flag = 2;
      while (!feof(fp)) {
        scanparam(result, c, &flag);
        c = fgetc(fp);
      }
      fclose(fp);
    } else {
      fprintf(stderr, "s21_cat %s: no such file or directory\n", argv[i]);
    }
  }
}
void scanparam(int result, unsigned char c, int *flag) {
  // bevnst
  static int strcount = 0;
  switch (result) {
    case 'b':
      case_b(c, flag, &strcount);
      break;
    case 'e':
      case_e(c);
      break;
    case 'v':
      case_v(c);
      break;
    case 'n':
      case_n(c, flag);
      break;
    case 's':
      case_s(c, flag);
      break;
    case 't':
      case_t(c);
      break;
    case 'E':
      case_E(c);
      break;
    case 'T':
      case_T(c);
      break;
    default:
      printf("%c", c);
  }
}
void case_e(unsigned char c) {
  if (c == '\n') {
    printf("$\n");
  } else {
    case_v(c);
  }
}
void case_E(unsigned char c) {
  if (c == '\n') {
    printf("$\n");
  } else {
    printf("%c", c);
  }
}
void case_t(unsigned char c) {
  if (c == '\t') {
    printf("^I");
  } else {
    case_v(c);
  }
}
void case_T(unsigned char c) {
  if (c == '\t') {
    printf("^I");
  } else {
    printf("%c", c);
  }
}
void case_v(unsigned char c) {
  if (c <= 31 && c != '\n' && c != '\t') {
    printf("^%c", '@' + c);
  } else if (c == 127) {
    printf("^?");
  } else if (c >= 128 && c <= 159) {
    printf("M-^%c", '@' + c - 128);
    VCASE;
  } else {
    printf("%c", c);
  }
}

void case_b(unsigned char c, int *flag, int *strcount) {
  if (*flag == 2) {
    NCASE(*strcount);
    *flag = 0;
  }
  if (c != '\n' && *flag == 0) {
    printf("%6d\t%c", ++(*strcount), c);
    *flag = 1;
  } else if (c != '\n' && *flag == 1) {
    printf("%c", c);
  } else if (c == '\n') {
    *flag = 0;
    printf("\n");
  }
}
void case_n(unsigned char c, int *flag) {
  static int strcount = 0;
  if (*flag == 2) {
    NCASE(strcount);
    printf("%6d\t", ++strcount);
    *flag = 3;
  }
  if (c == '\n') {
    printf("\n");
    printf("%6d\t", ++strcount);
  } else {
    printf("%c", c);
  }
}
void case_s(unsigned char c, int *flag) {
  if (*flag == -1) {
    *flag = 0;
  }
  if (c == '\n' && *flag < 2) {
    printf("\n");
    *flag += 1;
  } else if (c != '\n') {
    printf("%c", c);
    *flag = 0;
  }
}
