/**
 * 11. Напишите программу для подсчета
 * суммарного количества букв "м" и "н" в слове Y.
 */
#define _XOPEN_SOURCE 800

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 64

int getNumber(const char * str);

int main() {
  size_t buf_size = BUF_SIZE;
  char * buf;

  buf = (char *) malloc(buf_size * sizeof(char));
  if (buf == NULL) {
    perror("Не удалось выделить память для буфера.");
    exit(1);
  }

  printf("Введите слово Y: ");
  getline(&buf, &buf_size, stdin);

  buf[strlen(buf) - 1] = '\0';

  printf("\"м\" и \"н\" встречаются в Y %d раз.\n", getNumber(buf));
  return 0;
}

int getNumber(const char * str) {
  int n = 0;

  char * c1 = "м";
  char * c2 = "н";
  char * p = str;

  while ((p = strstr(p, c1)) != NULL) {
    ++n;
    printf("%d\n", strlen(c1));
    p += strlen(c1);
  }

  p = str;

  while ((p = strstr(p, c2)) != NULL) {
    ++n;
    p += strlen(c2);
  }

  return n;
}
