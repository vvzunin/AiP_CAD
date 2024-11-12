#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#define lmax 200

int check_input()
{
  int c, p;
  do {
    c = scanf("%d", &p);
    while (getchar() != '\n');
  } while (!c);
  return p;
}

//ввод массивa с проверкой упорядоченности
int input_array(int A[], char arr) {
  int i, n;
  do {
    printf("Введите длину массива %c (0 < n <= %d):", arr, lmax);
    n = check_input();
  } while (n < 1 || n > lmax);

  printf("\t %c[0] = ", arr);
  A[0] = check_input();
  for (i = 1;i < n;i++) {
    printf("\t %c[%d] = ", arr, i);
    A[i] = check_input();
  }
  return n;
}

void del_elem(int* na, int A[], int nb, int B[])
{
  int* ua, * ua1, * ub, d, * t;
  for (ua = A; ua < A + *na;ua++)
  {
    for (ua1 = A; ua1 < A + *na && (*ua != *ua1 || ua == ua1); ua1++);
    if (ua1 < A + *na) //повторяется
    {
      for (ub = B; ub < B + nb && *ua != *ub;ub++);
      if (ub == B + nb) //отсутствует
      {
        d = *ua; //что удаляем
        for (ua1 = ua, t = ua; ua1 < A + *na; ua1++)
          if (*ua1 != d) *t++ = *ua1;//остаются элементы, не равные удаляемому
        *na = t - A; //новая длина массива
        ua--; //на место удаленного может попасть повторяющийся элемент
      }
    }
  }
}

void print_array(int n, int A[]) {
  int* ua;
  for (ua = A; ua < A + n; ua++)
    printf("%5d", *ua);
  printf("\n");
}

int main() {
  int A[lmax], B[lmax], na, nb, len_a;
  printf("*************************************\n");
  printf("*     Семинар 2.02. Задание №04     *\n");
  printf("*************************************\n\n");

  printf("Ввод массива A:\n");
  na = input_array(A, 'A');
  printf("Ввод массива B:\n");
  nb = input_array(B, 'B');
  len_a = na; //исходная длина массива
  del_elem(&na, A, nb, B); //вызов функции

  // Вывод результата
  printf("\nПолученный результат:\n");
  if (!na)
    printf("Полное удаление!\n");
  else
    if (len_a == na)
      printf("Нет удаления!\n");
    else {
      printf("Измененный массив A:\n");
      print_array(na, A);
    }
  return 0;
}