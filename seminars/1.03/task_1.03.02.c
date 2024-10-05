#include <stdio.h>
#include <limits.h>
#define lmax 200

int main()
{
  int na, ma, A[lmax + 1][lmax + 1], nb, B[lmax + 1];
  int i, j, k;
  int flag, min;
  printf("*************************************\n");
  printf("*     Семинар 1.03. Задание №02     *\n");
  printf("*************************************\n\n");

  do {
    printf("Введите размер матрицы A[1:%3d][1:%3d]: ", lmax, lmax);
    k = scanf("%d%d", &na, &ma);
    while (getchar() != '\n');
  } while (na <= 0 || na > lmax || ma <= 0 || ma > lmax || k != 2);

  printf("Введите элементы матрицы A[1:%3d][1:%3d]:\n", na, ma);
  for (i = 1; i <= na; i++)
    for (j = 1; j <= ma; j++) {
      printf("\tВведите элемент [%3d][%3d]: ", i, j);
      scanf("%d", &A[i][j]);
    }

  do {
    printf("Введите длину массива B[1:%3d]: ", lmax);
    scanf("%d", &nb);
    while (getchar() != '\n');
  } while (nb <= 0 || nb > lmax);

  printf("Введите элементы массива B[1:%3d]:\n", nb);
  for (i = 1; i <= nb; i++) {
    printf("\tВведите элемент %3d: ", i);
    scanf("%d", &B[i]);
  }

  // printf("\nВведенная матрица A[1:%3d][1:%3d]:\n", na, ma);
  // for (i = 1; i <= na; i++)
  //   for (j = 1; j <= ma; j++)
  //     printf("\tA[1:%3d][1:%3d]: %5d\n", i, A[i][j]);

  printf("\nВведенная матрица A[1:%3d][1:%3d]:\n", na, ma);
  for (i = 1; i <= na; i++) {
    for (j = 1; j <= ma; j++) {
      printf("%5d", A[i][j]);
    }
    printf("\n");
  }

  printf("\nВведенный массив B[1:%3d]:\n", nb);
  for (i = 1; i <= nb; i++) {
    printf("\t%2d: %5d\n", i, B[i]);
  }


  // Поиск минимума
  for (min = INT_MAX, flag = 0, i = 1; i <= na; i++)
    for (j = 1; j <= ma; j++) {
      k = 1;
      while (k <= nb && A[i][j] != B[k])
        k = k + 1;
      if (k > nb && A[i][j] <= min) {
        min = A[i][j];
        flag = 1;
      }
    }

  printf("\nПолученный результат:\n");
  if (flag == 0)
    printf("Нет  минимума\n");
  else
    printf("min = %3d\n", min);

  return 0;
}