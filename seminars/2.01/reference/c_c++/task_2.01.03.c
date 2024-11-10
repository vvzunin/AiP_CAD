#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#define lmax 200

void in_matr(int A[][lmax], int* n) {//или int (*a)[lmax]
  //передаем массив указателей на строки, n– по адресу
  int i, j;

  printf("Введите размер матрицы n X n: ");
  scanf("%d", n);
  printf("Введите матрицу размером %2d на %2d \n", *n, *n);
  for (i = 0; i < *n; i++)
    for (j = 0; j < *n; j++)
      scanf("%d", A[i] + j);
}

//передаем  n   по значению
void out_matr(int A[][lmax], int n) {
  int i, j;

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++)
      printf("%5d", A[i][j]);
    printf("\n");
  }
}

int z(int n, int  B[][lmax]) {
  int min, max, * ui, * uj; //uj –указатель на начало столбца,
  //ui - на элемент матрицы

  min = INT_MAX;
  for (uj = *B;uj < *B + n; uj++) {
    max = *uj;
    for (ui = uj + lmax; ui < B[n - 1] + n; ui += lmax)
      if (abs(*ui) > abs(max))
        max = *ui;

    if (max < min)
      min = max;
  }
  return min;
}

int main() {
  int B[lmax][lmax], G, n;
  printf("*************************************\n");
  printf("*     Семинар 2.01. Задание №03     *\n");
  printf("*************************************\n\n");

  in_matr(B, &n); //ввод матрицы
  out_matr(B, n); //вывод матрицы
  G = z(n, B); //вычисления

  // Вывод результата
  printf("\nПолученный результат:\n");
  printf("G = %5d\n", G);

  return 0;
}