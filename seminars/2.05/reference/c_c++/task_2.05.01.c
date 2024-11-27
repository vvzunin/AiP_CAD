#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define strLen 81

// поиск подстрок
void selectSubStrings(
  int nStr, char arrStr[][strLen],
  int *nSubStr, char arrSubStr[][strLen], int arrNum[]) {
  int i;
  char *s, *s1; // s-на текущий символ. s1-на начало подстроки
  *nSubStr = 0; // число подстрок
  for (i = 0; i < nStr; i++) {
    s = arrStr[i];
    s1 = s;
    while (*s)
      if (*s == '[' || *s == ']') {
        if (s != s1) {                              // копирование подстроки
          arrNum[*nSubStr] = i;                     // запоминаем номер исходной cтроки
          strncpy(arrSubStr[*nSubStr], s1, s - s1); // копируем часть строки
          arrSubStr[*nSubStr][s - s1] = '\0';       // добавляем нуль-символ в конец копии
          (*nSubStr)++;                             // увеличиваем число подстрок
        }
        while (*s && (*s == '[' || *s == ']'))
          s++;
        s1 = s; // начало новой подстроки
      }
      else
        s++;
    if (s != s1) { // копирование подстроки, расположенной в конце строки
      arrNum[*nSubStr] = i;
      strncpy(arrSubStr[*nSubStr], s1, s - s1);
      arrSubStr[*nSubStr][s - s1] = '\0';
      (*nSubStr)++;
    }
  } // закрывающаяся скобка от цикла for
}

// поиск номера подстроки (вернет –1 если нет нужной подстроки)
int searchSubStringNumber(
  int nSubStr, char arrSubStr[][strLen]) {// возвращает номер подстроки
  int max = 0, maxi = -1, i;
  char *s; // указатель на текущий символ
  for (i = 0; i < nSubStr; i++) {
    s = arrSubStr[i];
    while (*s && isdigit(*s))
      s++;                 // пропуск цифр
    if (s - arrSubStr[i] > max) // цифр больше всего
      max = s - arrSubStr[i], maxi = i;
  }
  return (maxi);
}

// преобразование исходной строки
// возвращает признак преобразования
int transformString(char *s) {
  char *s1 = s, *s2;
  int f = 0;
  while (*s1 && *s1 == ' ')
    s1++; // поиск первого не пробела
  if (!*s1)
    *s ='\0', f=1; //все пробелы
  else {
    if (s != s1) // есть пробелы в начале строки
      f = 1;
    s2 = s + strlen(s) - 1;
    // s2-на символе перед '\0'
    while (*s2 == ' ')
      s2--;
    // s2-на последнем символе перед пробелом
    if (s2 != s + strlen(s) - 1)
      f = 1; // есть пробелы в конце строки
    strncpy(s, s1, s2 - s1 + 1);
    *(s + (s2 - s1) + 1) = '\0';
  }
  return f;
}

int main() {
  char arrStr[10][strLen], arrSubStr[30][strLen];
  int i, i1, nStr = 0, nSubStr, arrNum[30], f;

  // ввод строк до пустой или CTRL+Z
  puts("Input strings:");
  while (*gets(arrStr[nStr]) && *arrStr[nStr] && nStr < 10)
    nStr++;

  selectSubStrings(nStr, arrStr, &nSubStr, arrSubStr, arrNum);

  puts("Obtained result:");
  if (nSubStr == 0)
    puts("1. No substrings!");
  else {
    puts("1. Substings:");
    for (i = 0; i < nSubStr; i++)
      puts(arrSubStr[i]);
    i1 = searchSubStringNumber(nSubStr, arrSubStr);
    if (i1 == -1)
      puts("2. No necessary substring!");
    else {
      puts("2. Substring with the maximum number of digits in the beginning:");
      puts(arrSubStr[i1]);
      if (transformString(arrStr[arrNum[i1]])) {
        printf("3. %d\'th line of source array has been converted:\n", arrNum[i1]);
        // преобразованная %d-я строка исходного массива
        puts(arrStr[arrNum[i1]]);
      }
      else
        puts("3. No transformed string!");
    }
  }
  return 0;
}