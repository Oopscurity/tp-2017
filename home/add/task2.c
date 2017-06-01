/**
 * (2) Даны натуральное число n и целые числа a1,a2,...,an.
 * Определить:
 * (а) количество чисел ai, которые больше p;
 * (б) количество чисел ai, которые оканчиваются цифрой 5;
 * (в) количество чисел ai, которые кратны числу k.
 */
#include <stdio.h>
#include <assert.h>

int main() {
  int n;
  printf("Введите n: ");
  scanf("%d", &n);

  assert(n > 0);
  
  int p;
  printf("Введите p: ");
  scanf("%d", &p);

  int k;
  printf("Введите k: ");
  scanf("%d", &k);

  int num_gr_p;
  if (p >= n) {
    num_gr_p = 0;
  } else {
    num_gr_p = n - p;
  }

  int num_last_5 = n / 10 + (!(n % 5) && (n % 10));

  printf("A = { 1");

  int num_d_k;
  for (int i = 2; i <= n; ++i) {
    if (!(i % k)) {
      ++num_d_k;
    }
    
    printf(", %d", i);
  }

  printf(" };\n");
  printf("Чисел больше p: %d\n", num_gr_p);
  printf("Чисел, оканчивающихся на 5: %d\n", num_last_5);
  printf("Чисел, кратных %d: %d\n", k, num_d_k);

  return 0;
}
