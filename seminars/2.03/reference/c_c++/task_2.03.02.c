#include <stdio.h>
#include <ctype.h>

int main() {
  puts("*************************************");
  puts("*      Seminar 2.03. Task №02       *");
  puts("*************************************\n");
  
  //s-текущий
  //s1-начало подстроки
  //s2 – где было начало подстроки после удаления
  char str[100], *s = str, *s1, *s2;
  int flag = 0; // признак удаления
  puts("Input one string");
  gets(str);
  puts("Obtained result:");
  if (!*str)
    puts("\tString is empty!");
  else {
    while (*s)           // пока не конец строки
      if (isalpha(*s)) { // если латинская буква
        s1 = s;
        while (*s && isalpha(*s))
          s++;                 // пропуск лат. букв
        if (!((s - s1) % 2)) { // четная длина
          s2 = s1;
          flag = 1;
          while (*s)
            *s1++ = *s++; // удаление подстроки
          *s1 = *s;       // копирование нуль-символа
          s = s2;         //продолжаем с символа, где было начало подстроки
        }
      }
      else
        s++;

    if (!*str) // нуль-символ в начале строки
      puts("\tString is empty after changes!");
    else if (flag) // удаление было
      puts(str);
    else
      puts("\tNo changes!");
  }
  return 0;
}