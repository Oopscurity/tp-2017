/**
 * (10) Найдите периметр треугольника, заданного координатами
 * своих вершин, определив функцию для расчёта длины отрезка
 * по координатам его вершин.
 */
#include <stdio.h>
#include <math.h>
#include <string.h>

struct Point {
  double x;
  double y;
};

double d(struct Point * a, struct Point * b);

int main() {
  struct Point a, b, c;

  puts("[Расчет периметра треугольника ABC]");

  printf("Введите координаты A через пробел: ");
  scanf("%lf %lf", &a.x, &a.y);

  printf("Введите координаты B через пробел: ");
  scanf("%lf %lf", &b.x, &b.y);
  
  printf("Введите координаты C через пробел: ");
  scanf("%lf %lf", &c.x, &c.y);

  double p = d(&a, &b) + d(&a, &c) + d(&b, &c);
  printf("Периметр треугольника ABC P = %f\n", p);

  return 0;
}

double d(struct Point * a, struct Point * b) {
  double x = a->x - b->x, y = a->y - b->y;
  return sqrt(x*x + y*y);
}
