#include <stdio.h>
#include <stdlib.h>

#define ML 81
#define FCLR while (getc(file) != '\n')

void deln(char *s) {
  for (; *s && *s!='\n'; s++);
	*s='\0';
}

struct book {
  char author[ML], title[ML];
  int year, price;
};

void output(struct book books[], int n) {
  if (n == 0)
    puts("Empty array!");
  else {
    puts("Array of books:");
    for (int i = 0; i < n; i++) {
      printf("Book number: %d\n", i + 1);
      printf("\tAuthor.: %s\n", books[i].author);
      printf("\tTitile.: %s\n", books[i].title);
      printf("\tYear...: %d\n", books[i].year);
      printf("\tPrice..: %d\n", books[i].price);
      if ((i + 1) % 5 == 0)
      {
        puts("Press key");
        getchar();
      }
    }
  }
}

/*Функция ввода из файла массива книг*/
void fileReadBooks(int *n, struct book books[], char *fileName) {
  FILE *file = fopen(fileName, "r");
  if (!file){
    printf("ERROR");
    exit (1);
  }
  while(!feof(file)){
    if(fgets(books[*n].author, ML, file)){
      deln(books[*n].author);
      fgets(books[*n].title, ML, file);
      deln(books[*n].title);
      fscanf(file, "%d", &books[*n].year);
      fscanf(file, "%d", &books[*n].price);
      if (!feof(file))
        FCLR;
      *n = *n + 1;
    }
  }
  fclose(file);
}

/*Функция вывода в файл массива структур*/
void filePrintBooks(int n, struct book books[], char *fileName) {
  FILE *file = fopen(fileName, "w");
  for (int i = 0; i < n; i++) {
    fputs(books->title, file);
    fputs(books->author, file);
    fprintf(file, "%d\n", books->year);
    fprintf(file, "%d\n", books->price);
    books++;
  }
  fclose(file);
}

int main() {
  puts("*************************************");
  puts("*      Seminar 2.07. Task №02       *");
  puts("*************************************\n");
  struct book books[ML];
  int n;
  char fileNameIn[ML], fileNameOut[ML];
  printf("Input file name for input: ");
  gets(fileNameIn);
  fileReadBooks(&n, books, fileNameIn);
  if (!n)
    puts("Array is empty!");
  else {
    puts("Books was read: ");
    output(books, n);
    printf("Input file name for output: ");
    gets(fileNameOut);
    filePrintBooks(n, books, fileNameOut);
  }
  return 0;
}