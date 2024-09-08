#include <ctype.h>
#include <stdio.h>
#define lmax 200

int main() {
  int n, i, nmin;
  float s, a[lmax], x, y;
  printf("*************************************\n");
  printf("*     Семинар 1.01. Задание №01     *\n");
  printf("*************************************\n\n");

  printf("Введите нижнюю границу условия x:  ");
  scanf("%f", &x);
  printf("Введите верхнюю границу условия y: ");
  scanf("%f", &y);

  do {
    printf("Введите длину массива a [1:%d]: ", lmax);
    scanf("%d", &n);
  } while (n <= 0 || n > lmax);

  printf("Введите элементы массива [1:%d]:\n", n);
  for (i = 1; i <= n; i++) {
    printf("\tВведите элемент %2d: ", i);
    scanf("%f", &a[i]);
  }

  printf("Введенный массив [1:%d]:\n", n);
  for (i = 1; i <= n; i++) {
    printf("\t%2d: %5.2f\n", i, a[i]);
  }

  // Поиск последнего максимума в массиве
  nmin = 0;
  for (i = 1; i <= n; i++) {
    if ((nmin == 0 || a[i] <= a[nmin]) && a[i] >= x && a[i] < y) {
      nmin = i;
    }
  }

  printf("\nПолученный результат:\n");
  if (nmin == 0)
    printf("Нет минимума");
  else {
    printf("\tНомер:    %d\n", nmin);
    printf("\tЗначение: %5.2f\n", a[nmin]);
  }

  return 0;
}