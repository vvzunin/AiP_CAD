#include <stdio.h>
#define lmax 200

int main() {
  int na, ma, nb, A[lmax][lmax], B[lmax];
  float fv1, fv2;
  int k;
  do {
    printf("Введите размер (na, ma) матрицы A [1:%d]: ", lmax);
    k = scanf("%f%f", &fv1, &fv2);
    na = (int)fv1;
    ma = (int)fv2;
    while (getchar() != '\n'); 
  } while (k != 2 || na > lmax || na <= 0 || na != fv1 || ma > lmax || ma <= 0 || ma != fv2);

  do {
    printf("Введите размер (nb) массива [1:%d]: ", lmax);
    k = scanf("%f", &fv1);
    nb = (int)fv1;
    while (getchar() != '\n'); 
  } while (k != 1 || nb > lmax || nb <= 0 || nb != fv1);

  printf("Введите матрицу A\n");
  for(int i = 0; i < na; ++i) {
    for (int j = 0; j < ma; ++j) {
      scanf("%d", &A[i][j]);
    }
  }

  printf("Введите массив B\n");
  for (int i = 0; i < nb; ++i) {
    scanf("%d", &B[i]);
  }
  

  int i_m = -1, j_m = -1;
  short int assigned = 0;
  for (int i = 0; i < na; ++i) {
      for (int j = 0; j < ma; ++j) {
          int k = 0;
          while (k < nb && B[k] != A[i][j]) k++;
          if (k == nb && (assigned == 0 || A[i][j] < A[i_m][j_m])) {
              i_m = i;
              j_m = j;
              assigned = 1;        
          }
      }
  }
  if (!assigned)
    printf("Нет  минимума\n");
  else
    printf("min = %3d\n", A[i_m][j_m]);
  return 0;
}