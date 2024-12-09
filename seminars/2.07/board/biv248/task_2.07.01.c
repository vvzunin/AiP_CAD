#include <stdio.h>
#include <stdlib.h>
#define lmax 20

int search(char *filename) {
  FILE *file = fopen(filename, "r");
  int max, k, cur_num;
  if (!file) {
    printf("No file whith current name\n");
    exit(1);
  }
  fseek(file, 0L, SEEK_END);
  if(!ftell(file)) {
    printf("File is empty\n");
    exit(2);
  }
  rewind(file);
  k = fscanf(file,"%d",&cur_num);
  if (!k) {
    printf("Invalid data in file\n");
    exit(3);
  }
  max = cur_num;
  while(fscanf(file, "%d", &cur_num) && !feof(file)) {
    if (cur_num > max) {
      max = cur_num;
    }
  }
  fclose(file);
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