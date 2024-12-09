#include <stdio.h>
#include <stdlib.h>
#define lmax 20
int search(char *filename)
{
  FILE *fl;
  int max, i;
  fl = fopen(filename, "r");
  if (!fl)
  {
    printf("file not found");
    exit(1);
  }
  fseek(fl, 0L, SEEK_END);
  if (!ftell(fl))
  {
    printf("file is empty");
    exit(2);
  }
  rewind(fl);
  i = fscanf(fl, "%d", &max);
  if (!i)
  {
    printf("there are no numbers");
    exit(3);
  }
  while (!feof(fl))
  {
    fscanf(fl, "%d", &i);
    if (i > max)
      max = i;
  }
  fclose(fl);
  return max;
}

int main()
{
  puts("*************************************");
  puts("*      Seminar 2.07. Task №01       *");
  puts("*************************************\n");
  char filename[lmax];
  printf("input name");
  gets(filename);
  printf("maximum = %d", search(filename));
  return 0;
}