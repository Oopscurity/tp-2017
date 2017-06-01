/* Вариант 11 */

#include <stdio.h>

#define SIZE 5

int main() {
  float xs[SIZE] = { 1.1, 2.123, -1.04, 4.5, 10.0 };

  float a;
  printf("Введите A: ");
  scanf("%f", &a);

  float b;
  printf("Введите B: ");
  scanf("%f", &b);

  for (int i = 0; i < SIZE; ++i) {
    if (i % 2 == 0) {
      xs[i] -= b;
    } else {
      xs[i] += a;
    }
  }

  printf("Массив после изменения:\n\t");
  for (int i = 0; i < SIZE; ++i) {
    printf("%f, ", xs[i]);
  }
  printf("\n");

  return 0;
}
