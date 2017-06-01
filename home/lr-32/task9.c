/**
 * Промоделируйте бросание игрального  кубика  двумя  игроками  (по правилам игры
 * каждый из игроков может "выбросить" только одно число из диапазона от 1 до 6).
 * Определите, кто из игроков получил больше
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int cube();

int main() {
  srand(time(NULL));

  int a, b;
  a = cube();
  b = cube();

  printf("Первый игрок выбросил %d!\n", a);
  printf("Второй игрок выбросил %d!\n", b);

  if (a > b) {
    puts("Первый выиграл!");
  } else if (b > a) {
    puts("Второй выиграл!");
  } else {
    puts("Поровну!");
  }

  return 0;
}

int cube() {
  float base = ((float) rand()) / RAND_MAX;
  return (int) (1 + base * (6 - 1));
}
