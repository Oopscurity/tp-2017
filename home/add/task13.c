/**
 * (13) Найдите все целые числа из промежутка от a до b,
 * у которых количество делителей равно k. Значения переменных
 * a, b и k вводятся с клавиатуры.
 */
#include <stdio.h>

int divisors_num(int n);

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

  printf("Числа от %d до %d с кол-вом делителей, равным %d: ", a, b, k);
  for (int i = a; i <= b; ++i) {
    if (divisors_num(i) == k) {
      printf("%d ", i);
    }
  }
  printf("\n");

  return 0;
}

int divisors_num(int n) {
  int k = 0;

  for (int i = 2, j = i*i; j <= n; ++i, j = i*i) {
    if (n % i == 0) {
      k += 2 - (j == n);
    }
  }

  return k + 2 - (n == 1);
}
