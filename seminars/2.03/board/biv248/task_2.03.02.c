#include <stdio.h>
#include <ctype.h>

int main() {
  puts("*************************************");
  puts("*      Seminar 2.03. Task №02       *");
  puts("*************************************\n");
  
  char s[81];
  gets(s);

  int flag = 0;
  char * pc = s;
  while (*pc) {
    if (isalpha(*pc)) {
      char *j = pc;
      for(; *j && isalpha(*j); j++);
      if ((j - pc)%2 == 0) {
        flag = 1;
        int r = j - pc;
        for (; *j; j++) {
          *(j - r) = *j;
        }
        *(j - r) = '\0';
      }
      else
        pc = j-1;
    }
    pc++;
  }
  
  if (!*s) // нуль-символ в начале строки
      puts("\tString is empty after changes!");
    else if (flag) // удаление было
      puts(s);
    else
      puts("\tNo changes!");
  return 0;
}