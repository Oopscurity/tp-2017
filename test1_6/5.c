#include <stdio.h>

int main() {
  int n;
  printf("Введите n: ");
  scanf("%d", &n);

  float sum = 0;
  for (int i = 1; i <= n; ++i) {
    sum += 1 / (float) i;
  }
  printf("%f\n", sum);
  return 0;
}
