/**
 * 6. Напишите программу, выясняющую, можно ли
 * из букв слова X составить слово Y.
 */
#define _XOPEN_SOURCE 800

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 64

int letters(char * str, char * dest);
int check(char * src, char * target);

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

  printf("Из букв слова X ");
  if (!check(x, y)) {
    printf("не");
  }
  puts("возможно составить Y");

  free(x);
  free(y);

  return 0;
}

int letters(char * str, char * dest) {
  char * p = str;
  char let[2] = { '\0', '\0' };
  for (int i = 0, l = strlen(str); i < l; ++i, ++p) {
    if (strchr(dest, *p) == NULL) {
      let[0] = str[i];
      strcat(dest, let);
    }
  }
}

int check(char * src, char * target) {
  int sl = strlen(src);
  int tl = strlen(target);

  char * src_letters = (char *) malloc(sl * sizeof(char));
  char * target_letters = (char *) malloc(tl * sizeof(char));

  if (src_letters == NULL || target_letters == NULL) {
    perror("Не удалось выделить память для буфера.");
    exit(1);
  }

  memset(src_letters, 0, sl * sizeof(char));
  memset(target_letters, 0, tl * sizeof(char));
  
  letters(src, src_letters);
  letters(target, target_letters);

  int ok = 1;
  char * p = target_letters;
  for (int i = 0, l = strlen(target_letters); i < l; ++i, ++p) {
    if (!strchr(src_letters, *p)) {
      ok = 0;
      break;
    }
  }

  free(src_letters);
  free(target_letters);

  return ok;
}
