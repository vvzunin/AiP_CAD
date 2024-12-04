#include <stdio.h>
#include <string.h>

#define lmax 200
// пропуск символов до конца строки
#define CLR while (getchar() != '\n')

struct book {
  char author[20], title[60];
  int year, price;
};
struct book2010 {
  char author[20], title[60];
  int price;
};

// Функция ввода массива структур (каталога)
void inputBooks(int *n, struct book books[]) {
  char ch;
  *n = 0;
  do {
    printf("Book # %d\n", ++(*n));
    printf("Author.........: ");
    gets(books->author);
    printf("Title..........: ");
    gets(books->title);
    printf("Publishing year: ");
    scanf("%d", &books->year);
    printf("Price..........: ");
    scanf("%d", &books->price);
    CLR;
    printf("Continue (y/n)?:");
    ch = getchar();
    CLR;
    books++;
  } while ((ch == 'Y' || ch == 'y') && *n < lmax);
}

/*Функция формирования массива книг, изданных в 2010 г.*/
void form(struct book books[], struct book2010 books2010[], int n, int *n2010) {
  int i;
  for (i = 0, *n2010 = 0; i < n; i++)
    if (books[i].year == 2010) {
      strcpy(books2010->author, books[i].author);
      strcpy(books2010->title, books[i].title);
      books2010->price = books[i].price;
      (*n2010)++;
      books2010++;
    }
}

/* Функция вывода массива книг, изданных в 2010 году */
void outputBooks2010(struct book2010 books[], int n) {
  int i;
  if (!n)
    printf("No any books, published in 2010 year!\n");
  else {
    printf("Books, published in 2010 year:\n");
    for (i = 0; i < n; i++, books++) {
      printf("Book # %d\n", i + 1);
      printf("Author.........: %s\n", books->author);
      printf("Title..........: %s\n", books->title);
      printf("Price..........: %d\n", books->price);
    }
  }
}

int main() {
  puts("*************************************");
  puts("*      Seminar 2.06. Task №02       *");
  puts("*************************************\n");
  int n, n2010;
  struct book books[lmax];
  struct book2010 books2010[lmax];

  inputBooks(&n, books);           // ввод массива структур см. выше
  form(books, books2010, n, &n2010); // формирование нового массива
  outputBooks2010(books2010, n2010);       // вывод полученного массива
  return 0;
}