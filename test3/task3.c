#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 8
#define MIN -20
#define MAX 20

int abs(int n);

int main() {
  srand(time(NULL));

  printf("Массив: ");
  int xs[SIZE];
  for (int i = 0; i < SIZE; ++i) {
    xs[i] = (int) (MIN + ((float) rand()) / RAND_MAX * (MAX - MIN));
    printf("%d ", xs[i]);
  }
  printf("\n");

  printf("Искомые элементы: ");
  for (int i = 0; i < SIZE; ++i) {
    if (abs(xs[i]) % 10 != 7) {
      printf("%d ", xs[i]);
    } else {
      break;
    }
  }
  printf("\n");

  return 0;
}

int abs(int n) {
  if (n < 0) {
    return -n;
  }

  return n;
}
