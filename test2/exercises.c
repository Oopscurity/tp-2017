// Контрольная работа №2
// Вариант 5
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void task1(int n);
bool isPowerOf5(unsigned int i);

void task2(unsigned int n);

int task31(unsigned int n);
int task32(unsigned int n);

int main() {

  /* Задача 1 */ {
    printf("[Задача 1]\n");
    srand(time(NULL));
    task1(26);
    printf("\n");
  }
  /* Задача 2 */ {
    printf("[Задача 2]\n");
    task2(2);
    printf("\n");
  }

  /* Задача 3 */ { 
    {
      for (int i = 0; i < 10; ++i) {
        printf("[Задача 3.1] a[%d] = %d\n", i, task31(i));
      }
      printf("\n");
      for (int i = 0; i < 10; ++i) {
        printf("[Задача 3.2] a[%d] = %d\n", i, task32(i));
      }
    }
  }

  return 0;
}

bool isXPowerOfN(unsigned int x, unsigned int n) {
  if (x == 1) {
    return true;
  }
  if (x % n > 0) {
    return false;
  }

  unsigned int a = 1;
  while (a <= x) {
    if (a == x) {
      return true;
    }
    a = a * n;
  }

  return false;
}

void task1(int n) {
  int s = 0;
  int * arr = malloc(n * sizeof(int));
  for (int i = 0; i < n; ++i) {
    arr[i] = i + 1;
    printf("a[%d] = %d\n", i, arr[i]);

    if (isXPowerOfN(arr[i], 5)) {
      ++s;
    }
  }

  printf("Всего степеней пятерки: %d\n", s);
  free(arr);
}

void task2(unsigned int n) {
  // 6 -> 3
/*

*
**

*/
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j <= i; ++j) {
      printf("*");
    };
    printf("\n");
  }

  bool is = n % 2 == 0;
  if (is) {
    for (int i = 0; i < n; ++i) {
      printf("*");
    };
    printf("\n");
  }

  for (int i = is ? n - 2 : n - 1; i >= 0; --i) {
    for (int j = 0; j <= i; ++j) {
      printf("*");
    };
    printf("\n");
  }
}

int task31(unsigned int n) {
  if (n >= 2) {
    return task31(n - 1) + task31(n - 2);
  } else {
    return 1;
  }
}

int task32(unsigned int n) {
  if (n >= 2) {
    return 2 * task32(n - 1) - task32(n - 2);
  } else if (n == 1) {
    return 2;
  } else {
    return 1;
  }
}
