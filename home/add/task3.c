/**
 * (3) Даны натуральное число n и целые числа a1,a2,...,an.
 * Выясните, верно ли, что количество положительных чисел
 * не превышает 5.
 */
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define N_POS_MAX 5

int main() {
  int n;
  printf("Введите n: ");
  scanf("%d", &n);
  assert(n > 0);
  
  int
    * arr = (int *) malloc(n * sizeof(int)),
    * p = arr,
    n_pos = 0;
  for (int i = 1; i <= n; ++i, ++p) {
    printf("Введите A[%d]: ", i);
    scanf("%d", p);

    if (*p > 0) {
      ++n_pos;

      if (n_pos > N_POS_MAX) {
        printf("Количество положительных чисел превысило %d (%d)\n", N_POS_MAX, n_pos);
        break;
      }
    }
  }

  if (n_pos <= N_POS_MAX) {
    printf("Положительных чисел не более %d (%d)\n", N_POS_MAX, n_pos);
  }
  
  free(arr);
  return 0;
}
