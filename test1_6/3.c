#include <stdio.h>

int main() {
  int x;
  printf("Введите трехзначное натуральное число x: ");
  scanf("%d", &x);

  int s = x / 10 % 10,
      t = x % 10;
  if (s > t) {
    printf("Вторая цифра больше третьей: %d > %d.\n", s, t);
  } else if (t > s) {
    printf("Третья цифра больше второй: %d > %d.\n", t, s);
  } else {
    printf("Вторая и третья цифры равны.\n");
  }

  return 0;
}
