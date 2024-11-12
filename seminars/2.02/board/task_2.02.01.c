#include <stdio.h>
#include <limits.h>
#define lmax 200

void input_array(int* n, int A[])
{
  int* ua;
  printf("Введите длину массива A (0 < n <= %d):", lmax);
  scanf("%d", n);
  printf("Введите элементы массива A[0:%3d]:\n", *n - 1);
  for (ua = A; ua < A + *n; ua++)
    scanf("%d", ua);
}

void print_array(int n, int A[])
{
  int* ua;
  for (ua = A; ua < A + n; ua++)
    printf("%5d", *ua);
  printf("\n");
}

int main() {
  int A[lmax], n, * u1 = NULL, * u2 = NULL, * t, c;
  printf("*************************************\n");
  printf("*     Семинар 2.02. Задание №01     *\n");
  printf("*************************************\n\n");

  input_array(&n, A);

  printf("Введенный массив A:\n");
  print_array(n, A);

  for (t = A + n - 1; t >= A && u2 == NULL; t--) {
    if (*t % 2 != 0) {
      if (!u1)
        u1 = t;
      else
        u2 = t;
    }
  }

  // Вывод результата
  printf("\nПолученный результат:\n");
  if (!u1 && !u2)
    printf("Нет нечётных чисел!\n");
  else if (!u2)
    printf("В массиве лишь одно нечётное число!\n");
  else {
    c = *u1;
    *u1 = *u2;
    *u2 = c;
    print_array(n, A);
  }
  return 0;
}