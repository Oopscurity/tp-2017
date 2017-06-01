/**
 * (7) Вычислите сумму
 * sqrt(1 + sqrt(2 + ... + sqrt(50) ...))
 */
#include <stdio.h>
#include <math.h>

#define N 50.0

double f(double n);
double step(double acc, double i);

int main() {
  printf("f(%f) = %f\n", N, f(N));
  return 0;
}

double f(double n) {
  return step(0, n);
}

double step(double acc, double i) {
  if (i < 1) {
    return acc;
  }
  
  return step(sqrt(i + acc), i - 1);
}
