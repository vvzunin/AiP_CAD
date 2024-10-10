#include <stdio.h>
#define lmax 200

int main() {
  int na, nb, A[lmax+1], B[lmax+1], i, j, k;
  float fv;
  printf("*************************************\n");
  printf("*     Семинар 1.03. Задание №01     *\n");
  printf("*************************************\n\n");

  do {
    printf("Введите длину массива A[1:%3d]: ", lmax);
    k = scanf("%f", &fv);
    na = (int) fv;
    while (getchar()!='\n');
  } while (na <= 0 || na > lmax || k != 1 || na != fv);

  printf("Введите элементы массива A[1:%3d]:\n", na);
  for (i = 1; i <= na; i++) {
    printf("\tВведите элемент %3d: ", i);
    scanf("%d", &A[i]);
  }

  printf("\nВведенный массив A[1:%3d]:\n", na);
  for (i = 1; i <= na; i++) {
    printf("\t%2d: %5d\n", i, A[i]);
  }

  // Формирование массива B
  nb = 0;
  for (i = 1; i <= na; i++) {
    j = 1;
    while (j <= nb && (A[i] != B[j]))
      j = j + 1;
    if (j > nb) {
      nb = nb + 1;
      B[nb] = A[i];
    }
  }

  printf("\nПолученный результат:\n");
  if (na == nb)
    printf("Все элементы массива A неодинаковые!\n");
  else {
    printf("Массив B [1:%3d]:\n", nb);
    for (i = 1; i <= nb; i++) {
      printf("\t%2d: %5d\n", i, B[i]);
    }
  }
  
  return 0;
}