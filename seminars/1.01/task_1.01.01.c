#include <stdio.h>
#define lmax 200

int main() {
  int n, i, nmax;
  float s, a[lmax+1], max;
  printf("*************************************\n");
  printf("*     Семинар 1.01. Задание №01     *\n");
  printf("*************************************\n\n");

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
  max = a[1];
  nmax = 1;
  for (i = 2; i <= n; i++) {
    if (a[i] >= max) {
      max = a[i];
      nmax = i;
    }
  }

  printf("\nПолученный результат:\n");
  printf("\tНомер:    %d\n", nmax);
  printf("\tЗначение: %5.2f\n", max);

  return 0;
}