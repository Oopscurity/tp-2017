/**
 * 6. Напишите  программу,  выделяющую в слове Х
 * каждую букву "о" с помощью буквы "-" слева и справа.
 */
#define _XOPEN_SOURCE 800

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * clear(char * str);
char * append(char * str, const char * c, char * buf);
char * highlight(char * str, const char * pattern, const char * del);

int main() {
  size_t buf_size = 64;
  char * buf;

  buf = (char *) malloc(buf_size * sizeof(char));
  if (buf == NULL) {
    perror("Не удалось выделить память для буфера.");
    exit(1);
  }

  printf("Введите строку: ");
  getline(&buf, &buf_size, stdin);

  buf[strlen(buf) - 1] = '\0';
  highlight(buf, "o", "-");

  printf("Измененная строка: %s\n", buf);
  return 0;
}

char * append(char * str, const char * c, char * buf) {
  buf[0] = *c;
  return strcat(str, buf);
}

char * clear(char * str) {
  char * p = str;
  for (int i = 0, l = strlen(str); i < l; ++p, ++i) {
    *p = '\0';
  }
}

char * highlight(char * str, const char * pattern, const char * del) {
  int sl = strlen(str);
  char * b = (char *) malloc(sl * sizeof(char));
  memset(b, 0, sl * sizeof(char));

  strcpy(b, str);
  memset(str, 0, sl * sizeof(char));

  int pl = strlen(pattern), dl = strlen(del);
  char cbuf[2] = { '\0', '\0' };
  int prev_hightlighted = 0;
  
  for (int i = 0; i < sl; ++i, ++b) {
    if (strncmp(b, pattern, pl)) {
      append(str, b, cbuf);
    } else {
      if (i && prev_hightlighted != i - 1) {
        strcat(str, del);
      }

      append(str, b, cbuf);

      if (i != sl - 1) {
        strcat(str, del);
      }

      prev_hightlighted = i;
    }
  }

  return str;
}
