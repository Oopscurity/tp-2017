/**
 * 22. Подсчитайте, сколько одинаковых букв
 * стоят на одних и тех же местах в словах Х и Y.
 */
#define _XOPEN_SOURCE 800

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 64

int getNumber(char * s1, char * s2);

int main() {
  size_t buf_size = BUF_SIZE;
  char * x; char * y;

  x = (char *) malloc(buf_size * sizeof(char));
  y = (char *) malloc(buf_size * sizeof(char));
  if (x == NULL || y == NULL) {
    perror("Не удалось выделить память для буфера.");
    exit(1);
  }

  printf("Введите слово X: ");
  getline(&x, &buf_size, stdin);

  printf("Введите слово Y: ");
  getline(&y, &buf_size, stdin);

  x[strlen(x) - 1] = '\0';
  y[strlen(y) - 1] = '\0';

  printf("Количество идентичных букв на одинаковых местах: %d\n", getNumber(x, y));

  free(x);
  free(y);

  return 0;
}

// use with 2-byte characters
int getNumber(char * s1, char * s2) {
  int n = 0;
  int l1 = strlen(s1), l2 = strlen(s2);

  char * p1 = s1;
  char * p2 = s2;

  for (
    int i = 0, l = l1 > l2 ? l1 : l2;
    i < l;
    i += 2, p1 += 2, p2 += 2
  ) {
    if (strncmp(p1, p2, 2)) {
      ++n;
    }
  }

  return n;
}
