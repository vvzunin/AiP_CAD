#include <stdio.h>
#define lmax 200

int main()
{
  int na, A[lmax], nb, B[lmax], nc = 0, C[lmax], *ua, *ua1, *ub, *uc = C, k;
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
  for (ua = A; ua < A + na; ua++) {
    printf("\tВведите элемент %3d: ", (int)(ua - A));
    scanf("%d", ua);
  }

  do {
    printf("Введите длину массива B[1:%3d]: ", lmax);
    k = scanf("%f", &fv);
    nb = (int)fv;
    while (getchar() != '\n');
  } while (nb <= 0 || nb > lmax || k != 1 || nb != fv);

  printf("Введите элементы массива B[1:%3d]:\n", nb);
  for (ub = B; ub < B + nb; ub++) {
    printf("\tВведите элемент %3d: ", (int)(ub - B));
    scanf("%d", ub);
  }

  printf("\nВведенный массив A[1:%3d]:\n", na);
  for (ua = A; ua < A + na; ua++) {
    printf("\t%2d: %5d\n", (int)(ua - A), *ua);
  }

  printf("\nВведенный массив B[1:%3d]:\n", na);
  for (ub = B; ub < B + nb; ub++) {
    printf("\t%2d: %5d\n", (int)(ub - B), *ub);
  }

  for (ua = A; ua < A + na; ua++)
  { // проверка повторения *ua
    for (ua1 = A; ua1 < A + na && (*ua != *ua1 || ua == ua1); ua1++);
    if (ua1 < A + na) {// повторяется
      // проверка отсутствия *ua в B
      for (ub = B; ub < B + nb && *ua != *ub; ub++);
      if (ub == B + nb) // условие отсутствия
        *uc = *ua, uc++, nc++;
    }
  }

  printf("\nПолученный результат:\n");
  if (nc == 0)
    printf("\tМассив C пуст\n");
  else {
    printf("\tМассив C:");
    for (uc = C; uc < C + nc; uc++)
      printf("%7d", *uc);
    printf("\n");
  }

  return 0;
}