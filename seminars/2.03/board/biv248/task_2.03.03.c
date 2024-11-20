#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

// gcc -std=c99 -Wall task_2.03.03.c -lm

long MaxNumb(char *s) {// вернет число, либо -1
  long Max = -1;
  for(char *p = s; *p; ++p) {
    char *j;
    if(*p == '(') {
      j = p + 1;
      while(isdigit(*j)) ++j;
      if(*j == ')' && j - p > 1) {
        int value = atol(p+1);
        if(value > Max) Max = value;
      }
    }
  }
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