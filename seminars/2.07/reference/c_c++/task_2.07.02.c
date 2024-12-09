#include <stdio.h>
#include <stdlib.h>
#define ML 81
#define FCLR while (getc(fin) != '\n')
struct book
{
  char author[ML], title[ML];
  int year, price;
};
void output(struct book cat[], int k)
{
  if (k == 0)
    puts("Empty array");
  else
  {
    puts("Array of books:");
    for (int i = 0; i < k; i++)
    {
      printf("Book number:%d\n", i + 1);
      printf("Author:%s\nTitile:%s\n", cat[i].author, cat[i].title);
      printf("Year:%d\nPrice:%d\n", cat[i].year, cat[i].price);
      if ((i + 1) % 5 == 0)
      {
        puts("Press key");
        getchar();
      }
    }
  }
}
/*Функция ввода из файла массива книг*/

void freadcat(int *kol, struct book cat[], char *filename)
{
  FILE *fin;

  *kol = 0;
  if (!(fin = fopen(filename, "r")))
    printf("File %s does not exist\n", filename);
  else
  {
    /* Предполагается, что во входном файле нет пустых строк и название книги занимает одну строку */
    for (; !feof(fin); (*kol)++)
      if (fgets(cat[*kol].author, ML, fin))
      {
        deln(cat[*kol].author);
        fgets(cat[*kol].title, ML, fin);
        deln(cat[*kol].title);
        fscanf(fin, "%d", &cat[*kol].year);
        fscanf(fin, "%d", &cat[*kol].price);
        // Очистка входного потока
        if (!feof(fin))
          FCLR;
      }
    fclose(fin);
  }
}
/*Функция вывода в файл массива структур*/
void fprintcat(int kol, struct book cat[], char *filename)
{
  int i;
  FILE *fout;
  fout = fopen(filename, "w");
  for (i = 0; i < kol; i++)
    fprintf(fout, "%s\n%s\n%4d %d\n",
            cat[i].author, cat[i].title,
            cat[i].year, cat[i].price);
  fclose(fout);
}

int main()
{
  puts("*************************************");
  puts("*      Seminar 2.07. Task №02       *");
  puts("*************************************\n");
  struct book cat[ML];
  int kol;
  char fileNameIn[ML], fileNameOut[ML];
  printf("Input file name for input: ");
  gets(fileNameIn);
  freadcat(&kol, cat, fileNameIn);
  if (!kol)
    puts("Array is empty.");
  else
  {
    puts("Books was read: ");
    output(cat, kol);
    printf("Input file name for output: ");
    gets(fileNameOut);
    fprintcat(kol, cat, fileNameOut);
  }
  return 0;
}