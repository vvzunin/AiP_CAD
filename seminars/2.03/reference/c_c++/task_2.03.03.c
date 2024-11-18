#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

// gcc -std=c99 -Wall task_2.03.03.c -lm

long MaxNumb(char *s) {// вернет число, либо -1
  char *s1;
  long m, Max = -1;
  for (; *s; s++)
    if (*s == '(') {
      for (s1 = ++s; *s && isdigit(*s); s++); // пропуск цифр
      if (*s == ')' && s != s1 && Max < (m = atol(s1)))
        Max = m;
    } // есть скобка в конце, не две скобки рядом и больше Max
  return (Max);
}

int main() {
  puts("*************************************");
  puts("*      Seminar 2.03. Task №03       *");
  puts("*************************************\n");
  char str[10][81];
  int i = 0, j;
  long m;
  printf("Input strings:\n");
  // ввод максимум 10 строк, либо до пустой строки
  while (i < 10 && *gets(str[i])) i++;

  puts("Obtained result:");
  for (j = 0; j < i; j++)
    if ((m = MaxNumb(str[j])) == -1)
      printf("\tIn string %d condition not met \n ", j + 1);
    else
      printf("\tMaximum number in string %d is %ld\n", j + 1, m);
  return 0;
}