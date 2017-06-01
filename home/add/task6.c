/**
 * (6) Вычислите значение переменной x,
 * определив и использовав необходимую функцию:
 *
 *     sqrt(6) + 6   sqrt(13) + 13   sqrt(21) + 21
 * x = ——————————— + ————————————— + —————————————
 *          2              2               2
 */
#include <stdio.h>
#include <math.h>

double numer(double n);
double x();

int main() {
  printf("x = %f\n", x());
  return 0;
}

double numer(double n) {
  return (sqrt(n) + n);
}

double x() {
  return (numer(6.0) + numer(13.0) + numer(21.0)) / 2;
}
