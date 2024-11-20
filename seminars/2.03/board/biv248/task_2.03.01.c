#include <stdio.h>
#include <string.h>

int main()
{
  puts("*************************************");
  puts("*      Seminar 2.03. Task №01       *");
  puts("*************************************\n");

  char str[81];
  gets(str);

  int len = strlen(str);

  for (char *i = str; *i; i++) {
    if (*i == ' ') {
      char *j;
      for (j = i + 1; *j && *j == ' '; j++);
      if (j - i > 1) {
        int r = j - i;
        for (; *j; j++) {
          *(j - r + 1) = *j;
        }
        *(j - r + 1) = '\0';
      }
    }
  }

  puts("Obtained result:");
  if (len == strlen(str))
  {
    puts("sovpadait");
  }
  else
  {
    puts(str);
  }

  return 0;
}