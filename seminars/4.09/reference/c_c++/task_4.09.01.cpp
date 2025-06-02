#include <stdio.h>
#include <ctype.h>
#define ZNAK *pf == '+' || *pf == '-' /*макроопределение*/

char ae[80], *pf;

//прототипы функций
int fae (); //арифм. выражение
int fslag (); //слагаемое
int fmnog (); //множитель
int fper (); //переменная
int fid(); //идентификатор
int fconst(); //константа

int main () {
  printf("*************************************\n");
  printf("*      Seminar 4.09. Task №01       *\n");
  printf("*************************************\n\n");

  printf ("Input string:\n");
  gets(ae); pf=ae;
  printf ("String is:\n %s \n",pf);
  if (fae () || *pf ) /* то есть в выражении есть */
    /* ошибка, или после нуль-символа*/
    /* есть что-то еще, т.е. *pf !=0 */
    /* после fae указатель pf должен показывать на конец выражения: \0 */
    printf (" error - %d symbol %c \n", pf-ae,*pf);
    /* разность указателей pf-ae равна количеству символов, */
    /* то есть номеру символа */
  else printf (" is correct \n");
  return 0;
}

int fae () {
  if (ZNAK) pf++; /* по синтаксису - пропуск возможного знака*/
  /* проверка знака*/
  while (1) /* бесконечный цикл*/ {
    if (fslag()) return (1); /* есть ошибка в слагаемом*/
    if (ZNAK) pf++; /* пропуск знака в арифм. выражении*/
    else return (0); /* конец арифметического выражения */
  }
}

int fslag () {
  while (1) {
    if (fmnog()) return (1);
    if (*pf == '*' || *pf =='/') pf++;
    else return (0); /* конец арифметического выражения */
  }
}

int fmnog () {
  if (*pf =='(') /*выражение в скобках */ {
    pf++;
    if (fae()) return (1); /*рекурсия*/
    if (*pf != ')' ) return(1);
    else pf++; /* пропуск закрывающей скобки */
  } else
    if (fper() && fconst()) return(1);
    /* если не переменная и не константа */
  return (0);
}

int fper () {
  if (fid()) return(1); /* если нет идентификатора */
  if (*pf =='[') {
    do {
      pf++;
      if (fae()) return (1); /*рекурсия */
    } /* пока запятая, проверяется fae  в цикле */
    while (*pf ==',');
    if (*pf != ']' ) return(1);
    pf++;
  }
  return (0);
}

int fid() {
  if (isalpha(*pf)==0) return(1); /*первый символ - не буква */
  while (isalpha(*pf) || isdigit(*pf)) pf++;
  /* пропуск букв и цифр */
  return(0); /* в идентификаторе может быть одна буква */
}

int fconst()  /* константа без знака */ {
  int flag =1; /*флаг определяет наличие цифр в мантиссе */
  while (isdigit(*pf)) /*пока есть цифры */ {
    flag=0;
    pf++; /* пропуск цифр в мантиссе */
  }
  if (*pf =='.') {
    flag=1;
    pf++;
    while(isdigit(*pf)) {
      pf++; flag=0;
    }
  }
  if (flag) return(1); /* если нет цифр */
  if (*pf =='E') /* проверка экспоненты */ {
    pf++;
    if(ZNAK) pf++;
    if(!isdigit(*pf)) return(1);
    /* в порядке должна быть хотя бы одна цифра  */
    while (isdigit(*pf)) pf++;
  }
  return(0);
}
