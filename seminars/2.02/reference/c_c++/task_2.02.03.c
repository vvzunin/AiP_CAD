#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#define lmax 200

int check_input()
{
  int c, p;
  do {
    c = scanf("%d", &p);
    while (getchar() != '\n');
  } while (!c);
  return p;
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
  for (i = 1;i < n;i++)
    do {
      printf("\t %c[%d] = ", arr, i);
      A[i] = check_input();
    } while (A[i] <= A[i - 1]);
  return n;
}

void make_array(int A[], int B[], int C[], int na, int nb)
{
  int i, j, k;
  j = 0; //индекс в A
  k = 0; //индекс в B
  for (i = 0; i < na + nb; i++) //номер элемента в C
    if (j == na) //все эл-ты A уже в массиве  С
      C[i] = B[k++];
    else
      if (k == nb)    //все эл-ты B уже в массиве  С
        C[i] = A[j++];
      else  //есть эл-ты и в A и в B
        if (A[j] < B[k])
          C[i] = A[j++];
        else
          C[i] = B[k++];
}

void print_array(int n, int A[]) {
  int* ua;
  for (ua = A; ua < A + n; ua++)
    printf("%5d", *ua);
  printf("\n");
}

int main() {
  int A[lmax], B[lmax], C[2 * lmax], na, nb;
  printf("*************************************\n");
  printf("*     Семинар 2.02. Задание №03     *\n");
  printf("*************************************\n\n");

  printf("Ввод массива A:\n");
  na = input_array(A, 'A');
  printf("Ввод массива B:\n");
  nb = input_array(B, 'B');
  make_array(A, B, C, na, nb);


  // Вывод результата
  printf("\nПолученный результат:\n");
  print_array(na + nb, C);

  return 0;
}