#include <stdio.h>
#define lmax 200

int main()
{
  int na, A[lmax], i, j, k, x, L;
  float fv;
  printf("*************************************\n");
  printf("*     Семинар 1.04. Задание №03     *\n");
  printf("*************************************\n\n");

  do {
    printf("Введите длину массива A[1:%3d]: ", lmax);
    k = scanf("%f", &fv);
    na = (int)fv;
    while (getchar() != '\n');
  } while (na <= 0 || na > lmax || k != 1 || na != fv);

  printf("Введите элементы массива A[1:%3d]:\n", na);
  for (i = 0; i < na; i++) {
    printf("\tВведите элемент %3d: ", i);
    scanf("%d", &A[i]);
  }

  printf("\nВведенный массив A[1:%3d]:\n", na);
  for (i = 0; i < na; i++) {
    printf("\t%2d: %5d\n", i, A[i]);
  }
  
  i = 0;
  L = na;
  while (i < na) {
    j = 0;
    while (j < na && (A[i] != A[j] || i == j))
      j = j + 1;
    if (j < na) {
      x = A[i];
      k = i;
      for (j = i; j < na; j++)
        if (A[j] != x)
          A[k] = A[j], k = k + 1;
      na = k;
    }
    else
      i = i + 1;
  }


  printf("\nПолученный результат:\n");
  if (na == 0)
    printf("\tПолное удаление!\n");
  else if (L == na)
    printf("\tНет удаления!\n");
  else {
    printf("\tОставшиеся элементы массива A:\n");
    for (i = 0; i < na; i++)
      printf("\t%7d\n", A[i]);
  }
  return 0;
}