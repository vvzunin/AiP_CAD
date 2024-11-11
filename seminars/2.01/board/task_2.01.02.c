#include <stdio.h>
#define lmax 200

void input_array(int* n, int A[])
{
  int  i;

  printf("Введите длину массива A: ");
  scanf("%d", n);
  printf("Введите элементы массива A[0:%3d]:\n", *n - 1);
  for (i = 0; i < *n; i++)
    scanf("%d", &A[i]);
}

void print_array(int n, int A[])
{
  int i;

  for (i = 0;i < n;i++)
    printf("%5d", *(A + i));
  printf("\n");
}

int count(int A[], int B[], int na)
{
  int nb = 0;
  for (int i = 0; i < na; i++)
  {
    int j = 0;
    while (j < na && (A[i] != A[j] || i==j))
    {
      j++;
    }
    if (j < na)
    {
      j = 0;
      while(j < nb && (A[i] != B[j]))
      {
        j++;
      }
      if (j == nb)
      {
        B[nb] = A[i];
        nb++;
      }
    }
  }
  return nb;
}

int main() {
  int A[lmax], B[lmax], na, nb;
  printf("*************************************\n");
  printf("*     Семинар 2.01. Задание №02     *\n");
  printf("*************************************\n\n");

  input_array(&na, A);
  nb = count(A, B, na);

  // Вывод результата
  printf("\nПолученный результат:\n");
  if (nb == 0)
    printf("Нет массива B\n");
  else
  {
    printf("Массив B: ");
    print_array(nb, B);
  }

  return 0;
}