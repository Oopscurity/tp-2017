/* Вариант 7 */
#include <stdio.h>
#include <string.h>

#define BUF_SIZE 64

char * replace(char * str, char * patterns, char * next);
char * repl(char * str, char * res);
char * checkTriple(char * str, char * letters, char * registry);
char * removeTriple(char * str);
int isSuitable(char * word);
int getNumber(char * word);
int find(char let, char * registry);

int main() {
  char s[BUF_SIZE] = { '\0' };
  char x[BUF_SIZE] = { '\0' };

  char res[BUF_SIZE] = { '\0' };
  for (int i = 0; i < BUF_SIZE; ++i) {
    res[BUF_SIZE] = '\0';
  }

  char * pattern = "a";
  char * next = "qu";
  
  // printf("Введите строку: ");
  // gets(s);

  // repl(s, res);
  // printf("После изменения: %s\n", res);

  // printf("Введите строку: ");
  // gets(s);

  // removeTriple(s);
  // printf("После изменения: %s\n", s);

  // printf("Введите слово: ");
  // gets(s);
  // printf("Подходит (0/1): %d\n", isSuitable(s));

  printf("Введите слово x: ");
  gets(x);

  int num = getNumber(x);

  printf("Буква \"a\" встречается %d раз.\n", num);

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

char * repl(char * str, char * res) {
  size_t l = strlen(str);
  char * b = (char *) calloc(l, sizeof (char));
  strcpy(b, str);

  char * c1 = "qu";
  char * c2 = "a";

  while (strlen(b) != 0) {
    if (strncmp(b, c1, strlen(c1)) == 0) {
      strcat(res, c2);
      b += strlen(c1);
    } else if (strncmp(b, c2, strlen(c2)) == 0) {
      strcat(res, c1);
      b += strlen(c2);
    } else {
      printf("another!\n");

      strncat(res, b, 1);
      ++b;
    }
  }

  return res;
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
  char letters[BUF_SIZE] = { '\0' };

  int l = strlen(str);
  for (int i = 0; i < l; ++i) {
    if (!find(str[i], letters)) {
      char let[2] = { str[i], '\0' };
      strcat(letters, let);
    }
  }

  char triple[BUF_SIZE] = { '\0' };
  checkTriple(str, letters, triple);

  for (int i = 0, tl = strlen(triple); i < tl; ++i) {
    char let[2] = { triple[i], '\0' };
    replace(str, let, "");
  } 
  
  return str;
}

int isSuitable(char * word) {
  int is = 1, l = strlen(word);
  char let;

  if (l > 0) {
    let = word[0];
  } else {
    return is;
  }

  for (int i = 2; i < l; i += 2) {
    if (word[i] != let) {
      is = 0;
      break;
    }
  }

  return is;
}

int getNumber(char * word) {
  int n = 0, l = strlen(word);
  
  for (int i = 0, l = strlen(word); i < l; i += 4) {
    if (word[i] == 'a') {
      ++n;
    }
  }

  return n;
}
