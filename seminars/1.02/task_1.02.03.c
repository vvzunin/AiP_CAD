#include <ctype.h>
#include <stdio.h>
#define lmax 200

int main()
{
  int n, n1, np, i;
  float A[lmax+1], s;
  printf("*************************************\n");
  printf("*     Семинар 1.02. Задание №03     *\n");
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

  printf("\nВведенный массив A[1:%d]:\n", n);
  for (i = 1; i <= n; i++)
    printf("\t%2d: %5.2f\n", i, A[i]);

  // Поиск первого и последнего отрицательных элементов
  for (n1 = np = 0, i = 1; i <= n; i++)
    if (A[i] < 0) {
      if (n1 == 0)
        n1 = i;
      np = i;
    }

  if (n1 == 0)
    printf("\nНет отрицательных элементов!\n");
  else if (n1 == np)
    printf("\nОдин отрицательный элемент (%8.3f)!\n", A[n1]);
  else {
    s = 0;
    for (i = n1; i <= np; i++)
      s = s + A[i];
    printf("\ns = %10.5f\n", s);
  }
  return 0;
}