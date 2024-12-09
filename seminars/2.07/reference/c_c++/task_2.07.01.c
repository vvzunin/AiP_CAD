#include <stdio.h>
#include <stdlib.h>
#define lmax 20

int search(char *filename) {
  FILE *fl;
  int max, i;
  fl = fopen(filename, "r");
  if (!fl) {
    printf("File not found!\n");
    exit(1);
  }
  fseek(fl, 0L, SEEK_END);
  if (!ftell(fl)) {
    printf("File is empty\n");
    exit(2);
  }
  rewind(fl);
  i = fscanf(fl, "%d", &max);
  if (!i) {
    printf("There are no numbers!\n");
    exit(3);
  }
  while (!feof(fl)) {
    fscanf(fl, "%d", &i);
    if (i > max)
      max = i;
  }
  fclose(fl);
  return max;
}

int main() {
  puts("*************************************");
  puts("*      Seminar 2.07. Task №01       *");
  puts("*************************************\n");
  char filename[lmax];
  printf("Input fileName: ");
  gets(filename);
  printf("Maximum number: %d\n", search(filename));
  return 0;
}