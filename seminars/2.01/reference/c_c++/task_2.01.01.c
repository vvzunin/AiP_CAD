#include <stdio.h>
#include <limits.h>
#define lmax 200

float f(int n) {
  if (n == 0)
    return 1;
  else
    return f(n - 1) * n;
}

int main() {
  int n, k, num;
  float a, n1, k1;
  printf("*************************************\n");
  printf("*     Семинар 2.01. Задание №01     *\n");
  printf("*************************************\n\n");

  do {
    printf("Введите n и k (n >= 0, k >= n, k и n - целые): ");
    num = scanf("%f%f", &n1, &k1);
    while (getchar() != '\n');
  } while (num != 2 || n1 < 0 || k1 < n1 || n1 != (int)n1 || k1 != (int)k1 || n1 > INT_MAX || k1 > INT_MAX);

  n = (int)n1;	k = (int)k1;
  a = f(k) / f(k - n);

  // Вывод результата
  printf("\nПолученный результат:\n");
  printf("\tA(%d, %d) = %5.2f\n", n, k, a);

  return 0;
}