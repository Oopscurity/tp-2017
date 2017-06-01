#include <stdio.h>

int main() {
  /*
  {
    int x;
    printf("Введите трехзначное число: ");
    scanf("%d", &x);

    printf(
      "%d\n",
      x / 100 * 100 + (x % 10) * 10 + (x / 10) % 10
    );
  }

  {
    int x, y, z;
    printf("Введите x, y, z: ");
    scanf("%d %d %d", &x, &y, &z);
    printf("%d\n", !(x || (y && z)));
  }
  
  {
    int x, a;
    printf("Введите x, A: ");
    scanf("%d %d", &x, &a);
    
    if ((x % 10 + x / 10) % a == 0) {
      printf("Сумма цифр %d кратна %d\n", x, a);
    } else {
      printf("Сумма цифр %d не кратна %d\n", x, a);
    }
  }
  

  {
    int y;
    printf("Введите y: ");
    scanf("%d", &y);
    if (y > 2) {
      printf("%d\n", 2);
    } else if (y > 0) {
      printf("%d\n", 0);
    } else {
      printf("%d\n", -3 * y);
    }
  }

  {
    for (int i = 1, g = 453; i < 11; ++i, g += 453) {
      printf("%d фунт = %d г\n", i, g);
    }
  }

  {
    int limit = 20;
    int i, u;
    long sum = limit * limit;
    for (i = limit - 1, u = i*i; i > 0; --i, u = i*i) {
      sum -= u;
      sum *= sum;
    }
    printf("%d\n", sum);
  }
  */

  {
    int x = 101;
    while (x % 17 != 0) {
      ++x;
    }
    printf("%d\n", x);
  }

  {
    int min = 100, max = 200, d = 7;
    for (int i = min; i <= max; ++i) {
      if (i % 17 == 0) {
        printf("%d ", i);
      }
    }
    printf("\n");
  }

  {
    int m, n;
    printf("Введите m, n: ");
    scanf("%d %d", &m, &n);

    for (int s = 0, i = m; i < n; ++i, s = 0) {
      for (int j = i; j > 0; j /= 10) {
        // printf("%d ", j);
        s += j % 10;
        // printf("%d -> %d\n", j, s);
      }
      // printf("\n");

      if (s*s == m) {
        printf("%d ", i);
      }
    }
    printf("\n");
  }

  return 0;
}
