#include <stdio.h>
#include <stdlib.h>

#define ML 81
#define FCLR while (getc(fin) != '\n')

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
  FILE *fin;
  *n = 0;
  if (!(fin = fopen(fileName, "r")))
    printf("File %s does not exist!\n", fileName);
  else {
    /* Предполагается, что во входном файле нет пустых строк и название книги занимает одну строку */
    for (; !feof(fin); (*n)++)
      if (fgets(books[*n].author, ML, fin)) {
        deln(books[*n].author);
        fgets(books[*n].title, ML, fin);
        deln(books[*n].title);
        fscanf(fin, "%d", &books[*n].year);
        fscanf(fin, "%d", &books[*n].price);
        // Очистка входного потока
        if (!feof(fin))
          FCLR;
      }
    fclose(fin);
  }
}

/*Функция вывода в файл массива структур*/
void filePrintBooks(int n, struct book books[], char *fileName) {
  int i;
  FILE *fout;
  fout = fopen(fileName, "w");
  for (i = 0; i < n; i++)
    fprintf(fout, "%s\n%s\n%4d %d\n",
            books[i].author, books[i].title,
            books[i].year, books[i].price);
  fclose(fout);
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