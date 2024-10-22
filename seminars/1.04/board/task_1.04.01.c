#include <stdio.h>
#define lmax 200

int main()
{
  int na, A[lmax], k, *u1 = NULL, *u2 = NULL, *t;
  float fv;
  printf("*************************************\n");
  printf("*     Семинар 1.04. Задание №01     *\n");
  printf("*************************************\n\n");

  do {
    printf("Введите длину массива A[1:%3d]: ", lmax);
    k = scanf("%f", &fv);
    na = (int)fv;
    while (getchar() != '\n');
  } while (na <= 0 || na > lmax || k != 1 || na != fv);

  printf("Введите элементы массива A[1:%3d]:\n", na);
  for (t = A; t < A + na; t++) {
    printf("\tВведите элемент %3d: ", (int) (t - A));
    scanf("%d", t);
  }

  printf("\nВведенный массив A[1:%3d]:\n", na);
  for (t = A; t < A + na; t++) {
    printf("\t%2d: %5d\n", (int) (t - A), *t);
  }

  for(t = A; t < A+ na && u2 == NULL;t++){
    if (*t < 0 && u1 == NULL){
      u1 = t;
    }
    else if(*t < 0 && u1 != NULL){
      u2 = t;
    }
  }

  

  // перестановка и вывод результата
  printf("\nПолученный результат:\n");
  if (!u2)
    printf("\tНет двух отрицательных элементов!\n");
  else {
    printf("\t1й отрицательный: %d\n", *u1);
    printf("\t2й отрицательный: %d\n", *u2);
    k = *u1, *u1 = *u2, *u2 = k;
    printf("\tИзмененный массив А:\n");
    for (t = A; t < A + na; t++)
      printf("\t%2d: %5d\n", (int) (t - A), *t);
  }

  return 0;
}