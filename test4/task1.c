#include <stdio.h>
#include <string.h>

#define BUF_SIZE 32

char * replace(char * str, char * patterns, char * next);
char * repl(char * str, char * pattern);
int isSuitable(char * word);
int getNumber(char * word, char * pattern);

int main() {
  char s[BUF_SIZE], x[BUF_SIZE], y[BUF_SIZE];
  // char * pattern = "qu";
  // char * next = "a";

  // char * p1 = "abc";
  // char * p2 = "cba";
  
  // printf("Введите строку: ");
  // gets(s);

  // replace(s, pattern, next);
  // printf("После изменения: %s\n", s);

  // printf("Введите строку: ");
  // gets(s);

  // repl(s, p1);
  // repl(s, p2);
  // printf("После изменения: %s\n", s);

  // printf("Введите слово: ");
  // gets(s);
  // printf("Подходит (0/1): %d\n", isSuitable(s));

  printf("Введите слово xtese: ");
  gets(x);

  printf("Введите слово y: ");
  gets(y);
  printf("Введите слово y: ");

  int num = getNumber(x, y);

  printf("Сколько раз: %d\n", num);

  return 0;
}

char * replace(char * str, char * pattern, char * next) {
  char * b = (char *) calloc(strlen(str), sizeof (char));

  strcpy(b, str);
  str[0] = '\0';

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

char * repl(char * str, char * pattern) {
  char * next = "";
  replace(str, pattern, next);
  return str;
}

int isSuitable(char * word) {
  int is = 0;
  char prev2[2] = {};

  for (int i = 2, l = strlen(word); i < l; ++i) {
    if (i % 2 == 0) {
      if (word[i - 2] == 'o' && word[i - 1] == 't' && word[i] == 'k') {
        is = 1;
        break;
      }
    }
  }

  return is;
}

int getNumber(char * word, char * pattern) {
  printf("s");
  int n = 0;
  for (char * b = word; b != NULL; ++b) {
    if (strncmp(b, pattern, 2) == 0) {
      ++n;
    }
  }
  return n;
}
