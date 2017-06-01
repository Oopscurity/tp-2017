/**
 * (4) Даны натуральное число n и целые числа d1,d2,...,dn.
 * Выяснить, верно ли, что сумма тех чисел di, которые
 * не превышают  m, кратна целому числу p.
 */
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int main() {
  int n;
  printf("Введите n: ");
  scanf("%d", &n);
  assert(n > 0);

  int m;
  printf("Введите m: ");
  scanf("%d", &m);

  int p;
  printf("Введите p: ");
  scanf("%d", &p);
  
  int
    * arr = (int *) malloc(n * sizeof(int)),
    * b = arr,
    s = 0;
  for (int i = 1; i <= n; ++i, ++b) {
    printf("Введите D[%d]: ", i);
    scanf("%d", b);

    if (*b <= m) {
      s += *b;
    }
  }

  printf("Сумма чисел, не превышающих %d (%d), ", m, s);
  if (s % p) {
    printf("не ");
  }
  printf("кратна %d.\n", p);
  
  free(arr);
  return 0;
}
