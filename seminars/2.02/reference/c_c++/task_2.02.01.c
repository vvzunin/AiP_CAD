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
  int A[lmax], n, * u1, * u2, * t, c;
  printf("*************************************\n");
  printf("*     Семинар 2.02. Задание №01     *\n");
  printf("*************************************\n\n");

  input_array(&n, A);

  printf("Введенный массив A:\n");
  print_array(n, A);

  // Решение 1
  for (t = A, u1 = u2 = NULL; t < A + n; t++)
    if (*t % 2 != 0)
      if (u1 == NULL)
        u1 = t;
      else
        if (!u2)
          u2 = t;
        else
          u1 = u2, u2 = t;

  // Решение 2
  // for (t = A + n - 1, u1 = u2 = NULL; t >= A && (u1 == NULL); t--)
  //   if (*t % 2 != 0)
  //     if (u2 == NULL)
  //       u2 = t;
  //     else
  //       u1 = t;

  // Вывод результата
  printf("\nПолученный результат:\n");
  if (!u1)
    printf("Нет подходящих элементов!\n");
  else
    if (!u2)
      printf("Один нечетный!\n");
    else
      if (*u1 == *u2)
        printf("Значения равны!\n");
      else {
        c = *u1, * u1 = *u2, * u2 = c;
        printf("Изменный массив A:\n");
        print_array(n, A);
      }
  return 0;
}