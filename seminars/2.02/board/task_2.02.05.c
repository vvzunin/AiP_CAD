#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#define lmax 200

int check_input() {
  int c, p;
  do {
    c = scanf("%d", &p);
    while (getchar() != '\n');
  } while (!c);
  return p;
}

void in_matr(int A[][lmax], int* n, int* m) {//или int (*a)[lmax]
  //передаем массив указателей на строки, n– по адресу
  int i, j;

  do {
    printf("Введите высоту матрицы (0 < n <= %d):", lmax);
    *n = check_input();
  } while (*n < 1 || *n > lmax);
  do {
    printf("Введите ширину массива (0 < m <= %d):", lmax);
    *m = check_input();
  } while (*m < 1 || *m > lmax);

  printf("Введите матрицу размером %2d на %2d \n", *n, *m);
  for (i = 0; i < *n; i++)
    for (j = 0; j < *m; j++) {
      printf("\tA[%d][%d] = ", i, j);
      A[i][j] = check_input();
    }
}

//передаем  n   по значению
void out_matr(int A[][lmax], int n, int m) {
  int i, j;

  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++)
      printf("%5d", A[i][j]);
    printf("\n");
  }
}

//ввод массивa с проверкой упорядоченности
int input_array(int A[], char arr) {
  int i, n;
  do {
    printf("Введите длину массива %c (0 < n <= %d):", arr, lmax);
    n = check_input();
  } while (n < 1 || n > lmax);

  printf("\t %c[0] = ", arr);
  A[0] = check_input();
  for (i = 1;i < n;i++) {
    printf("\t %c[%d] = ", arr, i);
    A[i] = check_input();
  }
  return n;
}

short maxot(int n, int m, int A[][lmax], int k, int B[], int* max) {
  max = NULL;
  short flag = 0;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      if (A[i][j] < 0) {
        int kk = 0; for(; (kk < k) && (B[kk] != A[i][j]); ++k);
        if(kk == k) {
          if(max == NULL) { max = &A[i][j]; flag = 1; }
          else if(A[i][j] > *max) max = &A[i][j];
        }
      }
    }
  }  
  return flag;
}

int main() {
  int A[lmax][lmax], n, m, B[lmax], k, max;
  printf("*************************************\n");
  printf("*     Семинар 2.01. Задание №05     *\n");
  printf("*************************************\n\n");

  in_matr(A, &n, &m); //ввод матрицы
  out_matr(A, n, m); //вывод матрицы
  k = input_array(B, 'B'); //вычисления

  // Вывод результата
  printf("\nПолученный результат:\n");
  if (maxot(n, m, A, k, B, &max))
    printf("max = %7d\n", max);
  else
    printf("Подходящий максимум не найден!\n");
  return 0;
}