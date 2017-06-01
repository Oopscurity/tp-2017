/**
 * (12) Даны два натуральных числа. Выясните, в каком
 * из них больше цифр. (Напишите функцию для расчёта суммы
 * цифр натурального числа.)
 */
#include <stdio.h>
#include <string.h>

int digits_sum(int n);

int main() {
  int a;
  printf("Введите a: ");
  scanf("%d", &a);

  int b;
  printf("Введите b: ");
  scanf("%d", &b);
  
  int asum = digits_sum(a);
  int bsum = digits_sum(b);
  if (asum > bsum) {
    puts("Сумма первого числа больше!");
  } else if (asum < bsum) {
    puts("Сумма второго числа больше!");
  } else {
    puts("Поровну!");
  }

  return 0;
}

int digits_sum(int n) {
  int s = 0;

  do {
    s += n % 10;
  } while ((n /= 10) > 0);

  return s;
}
