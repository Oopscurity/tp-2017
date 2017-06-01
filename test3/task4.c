#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3
#define MAX 1000

int main() {
  srand(time(NULL));

  printf("Массив:\n");

  int xs[ROWS][COLS];
  for (int i = 0; i < ROWS; ++i) {
    for (int j = 0; j < COLS; ++j) {
      xs[i][j] = (int) (((float) rand()) / RAND_MAX * MAX);
      printf("%d\t", xs[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  float s = 0, n = 0;
  for (int i = 0; i < ROWS; ++i) {
    for (int j = 0; j < COLS; ++j) {
      if (xs[i][j] % 2 == 0) {
        s += xs[i][j];
        ++n;
      }
    }
  }

  printf("Среднее арифметическое четных элементов массива: %f\n", s / n);

  return 0;
}
