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

  for(i = 0; i < na; ++i) {
    // check if in b
    short int is_in_b = 0;
    for(j = 0; j < nb && !is_in_b; ++j) {
      if(B[j] == A[i]) is_in_b = 1;
    }
    if(!is_in_b) {
      short int is_repeat = 0;
      for(k = 0; k < na && !is_repeat; ++k) {
        if(A[i] == A[k] && k != i) { is_repeat = 1; }
      }
      if(is_repeat) C[nc++] = A[i];
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