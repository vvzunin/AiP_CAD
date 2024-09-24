#include <ctype.h>
#include <stdio.h>
#define lmax 200

int main() {
  int n, m, i, nmin;
  float A[lmax], B[lmax];
  printf("*************************************\n");
  printf("*     Семинар 1.02. Задание №02     *\n");
  printf("*************************************\n\n");

  do {
    printf("Введите длину массива A[1:%d]: ", lmax);
    scanf("%d", &n);
  } while (n <= 0 || n > lmax);

  printf("Введите элементы массива A[1:%d]:\n", n);
  for (i = 1; i <= n; i++) {
    printf("\tВведите элемент %2d: ", i);
    scanf("%f", &A[i]);
  }

  do {
    printf("Введите длину массива B[1:%d]: ", lmax);
    scanf("%d", &m);
  } while (m <= 0 || m > lmax);

  printf("Введите элементы массива B[1:%d]:\n", m);
  for (i = 1; i <= m; i++) {
    printf("\tВведите элемент %2d: ", i);
    scanf("%f", &B[i]);
  }


  printf("\nВведенный массив A[1:%d]:\n", n);
  for (i = 1; i <= n; i++) {
    printf("\t%2d: %5.2f\n", i, A[i]);
  }

  printf("\nВведенный массив B[1:%d]:\n", m);
  for (i = 1; i <= m; i++) {
    printf("\t%2d: %5.2f\n", i, B[i]);
  }

  // Поиск первого минимального элемента массива A
  nmin = 1;
  for (i = 2; i <= n; i++)
    if (A[i] < A[nmin])
      nmin = i;

  if (nmin != n)
    for (i=n; i >= nmin + 1; i--)
      A[i + m] = A[i];
  
  for (i=1; i <=m; i++)
    A[nmin + i] = B[i];

  printf("\nИзмененный массив A[1:%d]:\n", n+m);
  for (i = 1; i <= n + m; i++) {
    printf("\t%2d: %5.2f\n", i, A[i]);
  }
  return 0;
}