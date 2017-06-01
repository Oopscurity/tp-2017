/**
 * (14) Найдите все целые числа из промежутка от a до b,
 * у которых сумма делителей равна k. Значения переменных
 * a, b и k вводятся с клавиатуры.
 */
#include <stdio.h>

int divisors_sum(int n);

int main() {
  int a;
  printf("Введите a: ");
  scanf("%d", &a);

  int b;
  printf("Введите b: ");
  scanf("%d", &b);

  int k;
  printf("Введите k: ");
  scanf("%d", &k);

  printf("Числа от %d до %d с суммой делителей, равной %d: ", a, b, k);
  for (int i = a; i <= b; ++i) {
    if (divisors_sum(i) == k) {
      printf("%d ", i);
    }
  }
  printf("\n");

  return 0;
}

int divisors_sum(int n) {
  int s = n;

  for (int i = 2, m = n / 2; i <= m; ++i) {
    if (n % i == 0) {
      s += i;
    }
  }

  return s + (n != 1);
}
