#include <stdio.h>

int main() {
  int x, y;
  printf("Введите x, y: ");
  scanf("%d %d", &x, &y);

  if (x % 2 && y % 2) {
    printf("Оба числа являются нечетными.\n");
  } else {
    printf("Хотя бы одно из чисел является четным.\n");
  }

  return 0;
}
