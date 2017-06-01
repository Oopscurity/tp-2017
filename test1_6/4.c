#include <stdio.h>

float f(float x) {
  return x / (x*x + 5);
}

int main() {
  const float min = -1, max = 1;
  for (float x = min; x < max; x += 0.2) {
    printf("f(%f) = %f\n", x, f(x));
  }
  return 0;
}
