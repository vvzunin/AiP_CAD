#include <stdio.h>
#include <string.h>

int main() {
  puts("*************************************");
  puts("*      Seminar 2.03. Task №01       *");
  puts("*************************************\n");

  char s[81], *t = s, *d, blanc[] = "  "; // два пробела
  puts("Enter one string:");
  gets(s);
  int change = 0; // признак изменения строки
  while (d = strstr(s, blanc)) {
    change = 1;
    t = d;
    while (*t++)
      *t = *(t + 1); // сдвиг символов на 1 влево
  }

  puts("Obtained result:");
  if (change)
    puts('\t' + s);
  else
    puts("\tNo changes");
  return 0;
}