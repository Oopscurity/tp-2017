#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 5

int main() {
  srand(time(NULL));

  float b;
  printf("Введите B: ");
  scanf("%f", &b);

  printf("Массив:\n\t");

  float xs[SIZE];
  for (int i = 0; i < SIZE; ++i) {
    xs[i] = ((float) rand()) / RAND_MAX * b;
    printf("%f, ", xs[i]);
  }
  printf("\n");

  float s = 0;
  for (int i = 0; i < SIZE; ++i) {
    s += xs[i];
  }

  printf("Среднее арифметическое элементов массива: %f\n", s / SIZE);

  return 0;
}
