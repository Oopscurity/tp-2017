/**
 * (9) Даны основания и высоты двух равнобедренных трапеций.
 * Вычислите сумму их периметров, определив функцию для
 * расчёта периметра равнобедренной трапеции по её
 * основаниям и высоте.
 * 
 * Замечание: В комментариях укажите несколько
 * примеров с расчётами.
 */
#include <stdio.h>
#include <math.h>

#define TR_NUM 2

double hypotenuse(double a, double b);
double perimeter(double a, double b, double c);
double _abs(double n);
double find(double a, double b, double h);
double step(int i);

int main() {
  double s = 0;
  for (int i = 1; i <= TR_NUM; ++i) {
    s += step(i);
  }

  printf("Сумма периметров s = %f\n", s);
  return 0;
}

double hypotenuse(double a, double b) {
  return sqrt(a*a + b*b);
}

double perimeter(double a, double b, double c) {
  return a + b + 2*c;
}

double _abs(double n) {
  return n < 0 ? -n : n;
}

/**
 * 1. Вырожденная трапеция - прямоугольник [a = b = 1, h = 1]
 * P = a + b + 2 * sqrt(((a - b) / 2)^2 + h^2) =
 *   = 2 * a + 2 * sqrt(       0        + h^2) =
 *   = 2 * a + 2 * sqrt(       0        + h^2) =
 *   = 2 * a + 2 * h =
 *   = 2 * 1 + 2 * 1 = 4
 * 
 * 2. Равнобедренная трапеция [a = 4, b = 2, h = 1]
 * P = a + b + 2 * sqrt(((a - b) / 2)^2 + h^2) =
 *   = 4 + 2 + 2 * sqrt(((4 - 2) / 2)^2 + 1^2) =
 *   = 4 + 2 + 2 * sqrt(2) ~= 6 + 2 * 1.414    = 8.828 
 */
double find(double a, double b, double h) {
  return perimeter(a, b, hypotenuse(h, _abs((a - b) / 2)));
}

double step(int i) {
  printf("[Трапеция #%d]\n", i);

  double a, b, h;
  printf("Введите основание a: ");
  scanf("%lf", &a);
  printf("Введите основание b: ");
  scanf("%lf", &b);
  printf("Введите высоту h: ");
  scanf("%lf", &h);

  double p = find(a, b, h);
  printf("Периметр P = %f\n\n", p);

  return p;
}
