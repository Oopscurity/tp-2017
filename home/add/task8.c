/**
 * (8) Напишите программу, рисующую на экране
 * рамку из символов "*". Размер рамки может быть
 * произвольным.
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
  int w;
  printf("Введите ширину: ");
  scanf("%d", &w);

  int h;
  printf("Введите высоту: ");
  scanf("%d", &h);

  int realw = 2 * w - 1;

  char * border = (char *) malloc((realw + 1) * sizeof(char));
  char * body = (char *) malloc((realw + 1) * sizeof(char));
  if (border == NULL || body == NULL) {
    printf("Недостаточно памяти.");
    abort();
  }

  border[0] = body[0] = body[realw - 1] = '*';
  for (int i = 1; i < w; ++i) {
    strcat(border, " *");
  }
  
  if (w > 1) {
    memset(body + 1, ' ', realw - 2);
  }
  
  border[realw] = body[realw] = '\0';

  puts(border);
  for (int i = 2; i < h; ++i) {
    puts(body);  
  }
  puts(border);

  free(border);
  free(body);

  return 0;
}
