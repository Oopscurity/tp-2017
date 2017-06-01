/**
 * Реализация с помощью оператора цикла:
 * (1) Напечатайте числа в виде следующей таблицы:
 *
 * 1 1 1 1 1
 * 1 1 1 1
 * 1 1 1
 * 1 1
 * 1
 *
 */
#include <stdio.h>

#define ROWS 5
#define COLS 5

int main() {
  for (int i = ROWS; i > 0; --i) {
    for (int j = i; j > 0; --j) {
      printf("1 ");
    }
    putchar('\n');
  }

  return 0;
}
