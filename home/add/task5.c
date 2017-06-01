/**
 * Реализация с помощью функций:
 * (5) Определите значение
 * z = max(a, 2b) * max(2a - b, b),
 * где max(x, y) - максимальное из чисел x и y.
 */
#include <stdio.h>

float max(float x, float y);
float z(float a, float b);

int main() {
  float x;
  printf("Введите x: ");
  scanf("%f", &x);

  float y;
  printf("Введите y: ");
  scanf("%f", &y);

  printf("z(%f, %f) = %f\n", x, y, z(x, y));

  return 0;
}

float max(float x, float y) {
  return x > y ? x : y;
}

float z(float a, float b) {
  return max(a, 2*b) * max(2*a - b, b);
}
