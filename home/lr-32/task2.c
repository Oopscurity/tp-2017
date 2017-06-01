/**
 * (6) k случайных вещественных чисел n(i) (0 <= n(i) <b),  где k  -  нату-
 * ральное  число,  не превосходящее a.  Значения переменных k,  a и b
 * вводятся с клавиатуры;
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <float.h>

float getRand(float min, float max);

int main() {
  srand(time(NULL));

  float a;
  printf("Введите a: ");
  scanf("%f", &a);

  float b;
  printf("Введите b: ");
  scanf("%f", &b);

  int k = (int) getRand(0, a);
  printf("k (k = %d) случайных вещественных чисел:\n", k);

  for (int i = 0; i < k; ++i) {
    printf("\tn(%d) = %f\n", i, getRand(0, b));
  }
  printf("\n");

  return 0;
}

float getRand(float min, float max) {
  float base = (float) rand() / (float) RAND_MAX;
  return min + base * (max - min);
}
