#include <ctype.h>
#include <stdio.h>
#define lmax 200

int main() {
  int k, n, i;
  float A[lmax+1], B, L;
  printf("*************************************\n");
  printf("*     Семинар 1.02. Задание №01     *\n");
  printf("*************************************\n\n");

  do {
    printf("Введите длину массива A[1:%d]: ", lmax);
    scanf("%d", &k);
  } while (k <= 0 || k > lmax);

  printf("Введите элементы массива A[1:%d]:\n", k);
  for (i = 1; i <= k; i++) {
    printf("\tВведите элемент %2d: ", i);
    scanf("%f", &A[i]);
  }

  printf("Введите значение числа B (B < A[i] <= L): ");
  scanf("%f", &B);

  printf("Введите значение числа L (%f < A[i] <= L): ", B);
  scanf("%f", &L);

  printf("\nВведенный массив A[1:%d]:\n", k);
  for (i = 1; i <= k; i++) {
    printf("\t%2d: %5.2f\n", i, A[i]);
  }

  // Удаление элементов по условию.
  n = 0;
  for (i = 1; i <= k; i++) {
    if ((A[i] > L) || (A[i] <= B)) {
      n = n + 1;
      A[n] = A[i];
    }
  }

  printf("\nПолученный результат:\n");
  if (n == 0)
    printf("Полное удаление!");
  else {
    if (n == k)
      printf("Нет удаления!\n");
    else {
      printf("Введенный массив [1:%d]:\n", n);
      for (i = 1; i <= n; i++) {
        printf("\t%2d: %5.2f\n", i, A[i]);
      }
    }
  }
  return 0;
}