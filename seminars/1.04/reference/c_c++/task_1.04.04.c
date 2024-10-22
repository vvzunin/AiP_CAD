#include <stdio.h>
#define lmax 200

int main()
{
  int n, m, A[lmax][lmax], i, j, *u1, *u2, c, k;
  float fv1, fv2;
  printf("*************************************\n");
  printf("*     Семинар 1.04. Задание №04     *\n");
  printf("*************************************\n\n");

  do
  {
    printf("Введите размер матрицы A[1:%3d][1:%3d]: ", lmax, lmax);
    k = scanf("%f%f", &fv1, &fv2);
    while (getchar() != '\n');
    n = (int)fv1;
    m = (int)fv2;
  } while (n <= 0 || n > lmax || m <= 0 || m > lmax ||
           k != 2 || n != fv1 || m != fv2);

  printf("Введите элементы матрицы A[1:%3d][1:%3d]:\n", n, m);
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
    {
      printf("\tВведите элемент [%3d][%3d]: ", i, j);
      scanf("%3d", &A[i][j]);
    }

  printf("\nВведенная матрица A[1:%3d][1:%3d]:\n", n, m);
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      printf("%5d", A[i][j]);
    }
    printf("\n");
  }

  u1 = u2 = NULL;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) {
      if (A[i][j] > 0 && u1 == NULL)
        u1 = &A[i][j];
      if (A[i][j] < 0)
        u2 = &A[i][j];
    }

  printf("\nПолученный результат:\n");
  if (!u1)
    printf("\tНет положительных элементов!\n");
  else if (!u2)
    printf("\tНет отрицательных элементов!\n");
  else {
    c = *u1, *u1 = *u2, *u2 = c;
    printf("\tИзмененная матрица А:\n\t\t");
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++)
        printf("%5d", A[i][j]);
      printf("\n\t\t");
    }
  }

  return 0;
}