#include <stdio.h>
#define lmax 200

int main() {
  int na, A[lmax], nb, B[lmax], nc = 0, C[lmax], i, j, k;
  float fv;
  printf("*************************************\n");
  printf("*     Семинар 1.04. Задание №02     *\n");
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

  do {
    printf("Введите длину массива B[1:%3d]: ", lmax);
    k = scanf("%f", &fv);
    nb = (int)fv;
    while (getchar() != '\n');
  } while (nb <= 0 || nb > lmax || k != 1 || nb != fv);

  printf("Введите элементы массива B[1:%3d]:\n", nb);
  for (i = 0; i < nb; i++) {
    printf("\tВведите элемент %3d: ", i);
    scanf("%d", &B[i]);
  }

  printf("\nВведенный массив A[1:%3d]:\n", na);
  for (i = 0; i < na; i++) {
    printf("\t%2d: %5d\n", i, A[i]);
  }

  printf("\nВведенный массив B[1:%3d]:\n", na);
  for (i = 0; i < nb; i++) {
    printf("\t%2d: %5d\n", i, B[i]);
  }

  for (i = 0; i < na; i++) { // проверка повторения A[i]
    for (j = 0; j < na && (A[i] != A[j] || i == j); j++);
    if (j < na) // повторяется
    { // проверка отсутствия A[i] в B
      for (j = 0; j < nb && A[i] != B[j]; j++);
      // цикл закрыт
      if (j == nb) // условие отсутствия
        C[nc++] = A[i];
    }
  }
  
  printf("\nПолученный результат:\n");
  if (nc == 0)
    printf("\tМассив C пуст\n");
  else {
    printf("\tМассив C:");
    for (i = 0; i < nc; i++)
      printf("%7d", C[i]);
    printf("\n");
  }

  return 0;
}