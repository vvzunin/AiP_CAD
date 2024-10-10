#include <stdio.h>
#define lmax 200

int main() {
  int na, nb = 0, A[lmax], B[lmax], k;
  float fv;
  do {
    printf("Введите размер массива A:");
    k = scanf("%f", &fv);
    na = (int) fv;
    while (getchar() != '\n'); 
  } while (k != 1 || na > lmax || na <= 0 || na != fv);

  for (int i = 0; i < na; i++) {
    scanf("%d", &A[i]);
  }
  for (int i = 0; i < na; i++) {
    int j = 0;
    while (j < nb && B[j] != A[i])
      j++;
    if (j == nb) {
      B[nb] = A[i];
      nb++;
    }
  }

  for (int i = 0; i < nb; i++) {
    printf("%d\t", B[i]);
  }

  return 0;
}