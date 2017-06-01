#include <stdio.h>

int main() {
  int x, y;
  printf("Введите x, y: ");
  scanf("%d %d", &x, &y);

  printf("%d\n", (y && !x) || !y);
  return 0;
}
