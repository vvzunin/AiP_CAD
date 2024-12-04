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
    printf("\tAuthor.........: ");
    gets(books->author);
    printf("\tTitle..........: ");
    gets(books->title);
    printf("\tPublishing year: ");
    scanf("%d", &books->year);
    printf("\tPrice..........: ");
    scanf("%d", &books->price);
    CLR;
    printf("Continue (y/n)?:");
    ch = getchar();
    CLR;
    books++;
  } while ((ch == 'Y' || ch == 'y') && *n < lmax);
}

/*Функция формирования массива книг, изданных в 2010 г.*/
void form(struct book books[], int n, struct book2010 books_2010[], int *k) {
  for(int i = 0; i < n; ++i, ++books) {
    if(books->year == 2010) {
      strcpy(books_2010->author, books->author);
      strcpy(books_2010->title, books->title);
      books_2010->price = books->price;
      ++*k;
      ++books_2010;
    }
  }
}

/* Функция вывода массива книг, изданных в 2010 году */
void outputBooks2010(struct book2010 books[], int n) {
  if (n == 0)
    printf("No any books, published in 2010 year!\n");
  else {
    printf("Books, published in 2010 year:\n");
    for (int i = 0; i < n; i++, books++) {
      printf("Book #%d\n", i);
      printf("\tAutor: %s\n", books->author);
      printf("\tTitle: %s\n", books->title);
      printf("\tPrice: %d\n", books->price);
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
  inputBooks(&n, books);
  form(books, n, books2010, &n2010);
  outputBooks2010(books2010, n2010);
  return 0;
}