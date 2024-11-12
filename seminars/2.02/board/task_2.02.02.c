#include <stdio.h>
#define lmax 200

void input_array(int* n, int A[]) {
  int* ua;
  printf("Введите длину массива(0 < n <= %d):", lmax);
  scanf("%d", n);
  printf("Введите элементы массива [0:%3d]:\n", *n - 1);
  for (ua = A; ua < A + *n; ua++)
    scanf("%d", ua);
}

void print_array(int n, int A[]) {
  int* ua;
  for (ua = A; ua < A + n; ua++)
    printf("%5d", *ua);
  printf("\n");
}

void change(int *na, int A[], int nb, int B[]) {
  int* ua;
  int* min = A;
  for (ua = A + 1; ua < A + *na; ++ua) {
    if (*ua < *min) min = ua;
  }

  if (min != A + *na - 1) {
    for (ua = min + 1; ua < min + nb + 1; ua++) {
      *(ua + nb) = *ua;
    }
  }

  int* ub;
  for (ub = B; ub < B + nb; ub++) {
    *(min + 1 + (ub - B)) = *ub;
  }

  *na = *na + nb;
}

int main() {
  int A[lmax], B[lmax], na, nb;
  printf("*************************************\n");
  printf("*     Семинар 2.02. Задание №02     *\n");
  printf("*************************************\n\n");

  printf("Ввод массива A:\n");
  input_array(&na, A);
  printf("Ввод массива B:\n");
  input_array(&nb, B);

  change(&na, A, nb, B);

  // Вывод результата
  printf("\nПолученный результат:\n");
  printf("Измененный массив A: ");
  print_array(na, A);

  return 0;
}