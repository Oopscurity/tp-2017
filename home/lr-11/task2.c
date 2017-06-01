#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define N 8

int getRandom(int min, int max);
int find(int * arr, int k);

int main() {
  srand(time(NULL));

  int a[N];

  printf("Исходный массив: ");
  for (int i = 0; i < N; ++i) {
    a[N] = getRand(1, 40);
    printf("%d ", a[N]);
  }
  puts("");

  int k = N / 2;
  
  find(a, k);
  printf("Результат: %d\n", a[k]);

  return 0;
}

int getRand(int min, int max) {
  float base = ((float) rand()) / RAND_MAX;
  return (int) (min + base * (max - min));
}

int find(int * arr, int k) {
  int l = 1, r = N;
  int i, j, w, x;

  while (l < r) {
    x = arr[k];
    i = l;
    j = r;

    do {
      while (arr[i] < x) ++i;
      while (x < arr[j]) --j;
      
      if (i <= j) {
        w = arr[i]; arr[i] = arr[j]; arr[j] = w;
        ++i; --j;
      }
    } while (i <= j);

    if (j < k) {
      l = i;
    }
    if (k < i) {
      r = j;
    }
  }
}
