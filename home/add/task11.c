/**
 * (11) Дано натуральное число n и целые числа a1, a2, ..., an.
 * Найдите количество чисел ai (i = 1, 2, ..., n), являющихся
 * полными квадратами. (Напишите функцию, позволяющую
 * распознавать полные квадраты.)
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int is_square_number(int n);

int main() {
  int n;
  printf("Введите n: ");
  scanf("%d", &n);
  assert(n > 0);

  int
    * arr = (int *) malloc(n * sizeof(int)),
    * b = arr,
    k = 0;
  for (int i = 1; i <= n; ++i, ++b) {
    printf("Введите A[%d]: ", i);
    scanf("%d", b);
    
    if (is_square_number(*b)) {
      ++k;
    }
  }

  printf("Всего полных квадратов: %d\n", k);

  free(arr);
  return 0;
}

int is_square_number(int n) {
  if (!n) {
    return 1;
  }

  int s = 0;
  for (int i = 1; s < n; i += 2) {
    s += i;
  }
  
  return s == n;
}
