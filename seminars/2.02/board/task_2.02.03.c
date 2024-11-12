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
  int* ua = A;
  int* ub = B;
  int* uc = C; 
  while ((ua != A + na) && (ub != B + nb)) {
    if (*ua < *ub) {
      *uc = *ua;
      ++ua; ++uc;
    }
    else { 
      *uc = *ub;
      ++ub; ++uc;
    }
  }
  if (ua == A + na) {
    while(ub != B + nb) {
      *uc = *ub;
      ++ub; ++uc;
    }
  }
  else {
    while(ua != A + na) {
      *uc = *ua;
      ++ua; ++uc;
    }
  }
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