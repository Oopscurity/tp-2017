#include <stdio.h>

int ispos(int n);
int significant_bits(int n);

int main() {
  int x;
  
  printf("Введите натуральное число: ");
  scanf("%d", &x);

  int is = ispos(x);
  printf("Положительно ли число %d: %d\n", x, is);

  if (x >= 0) {
    printf("Количество значащих битов числа %d: %d\n", x, significant_bits(x));
  }

  return 0;
}

/**
 * 3*. Напишите программу, определяющую, является ли
 * отрицательным данное натуральное число.
 */
int ispos(int n) {
  size_t bits = sizeof(int) * 8 - 1;
  return ((~n + 1) >> bits & 0x1);
}

/**
 * 6*. Напишите программу, определяющую количество
 * значащих битов в двоичном представлении
 * натурального числа
 */
int significant_bits(int n) {
  size_t l = sizeof(int) * 8 - 1;
  int x = l;

  while (n >> x != 1 && x != -1) {
    --x;
  }

  return ++x;
}
