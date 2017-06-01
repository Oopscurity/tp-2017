/**
 * 11. Вычеркните из слова X те буквы,
 * что встречаются трижды.
 */
#define _XOPEN_SOURCE 800

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 64

char * replace(char * str, char * pattern, char * next);
int find(char let, char * registry);
char * checkTriple(char * str, char * letters, char * registry);
char * removeTriple(char * str);

int main() {
  size_t buf_size = BUF_SIZE;
  char * buf;

  buf = (char *) malloc(buf_size * sizeof(char));
  if (buf == NULL) {
    perror("Не удалось выделить память для буфера.");
    exit(1);
  }

  printf("Введите слово X: ");
  getline(&buf, &buf_size, stdin);

  buf[strlen(buf) - 1] = '\0';
  removeTriple(buf);

  printf("Измененная строка: %s\n", buf);
  return 0;

  return 0;
}

char * replace(char * str, char * pattern, char * next) {
  size_t bytes_in_str = strlen(str) * sizeof(char);
  char * b = (char *) malloc(bytes_in_str);
  memset(b, 0, bytes_in_str);

  strcpy(b, str);
  memset(str, 0, bytes_in_str);

  size_t lastIndex, appear, patLen = strlen(pattern);

  for (char *sub = strstr(b, pattern); sub != NULL; sub = strstr(b, pattern)) {
    appear = strlen(b) - strlen(sub);
    strncat(str, b, appear);
    strcat(str, next);

    lastIndex = appear + patLen;
    b += lastIndex;
  }
  strcat(str, b);

  return str;
}

int find(char let, char * registry) {
  for (int i = 0, l = strlen(registry); i < l; ++i) {
    if (registry[i] == let) {
      return 1;
    }
  }

  return 0;
}

char * checkTriple(char * str, char * letters, char * registry) {
  int n, sl = strlen(str);
  char c;
  for (int i = 0, l = strlen(letters); i < l; ++i) {
    c = letters[i];
    n = 0;
    for (int j = 0; j < sl; ++j) {
      if (str[j] == c) {
        ++n;
      }
    }

    if (n == 3) {
      char let[2] = { c, '\0' };
      strcat(registry, let);
    }
  }

  return str;
}

char * removeTriple(char * str) {
  char letters[BUF_SIZE];
  memset(letters, 0, BUF_SIZE * sizeof(char));

  int l = strlen(str);
  for (int i = 0; i < l; ++i) {
    if (!find(str[i], letters)) {
      char let[2] = { str[i], '\0' };
      strcat(letters, let);
    }
  }

  char triple[BUF_SIZE];
  memset(triple, 0, BUF_SIZE * sizeof(char));
  checkTriple(str, letters, triple);

  for (int i = 0, tl = strlen(triple); i < tl; ++i) {
    char let[2] = { triple[i], '\0' };
    replace(str, let, "");
  } 
  
  return str;
}
