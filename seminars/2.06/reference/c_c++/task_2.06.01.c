#include <stdio.h>

#define lmax 200
// пропуск символов до конца строки
#define CLR while (getchar() != '\n')

struct book {
  char author[20], title[60];
  int year, price;
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

// Функция поиска самой дорогой книги
struct book *findMostExpensive(int n, struct book books[]) {
  int i;
  struct book *mostExpensiveBook = books++;
  for (i = 1; i < n; i++, books++)
    if (books->price > mostExpensiveBook->price)
      mostExpensiveBook = books;
  return (mostExpensiveBook);
}

int main() {
  puts("*************************************");
  puts("*      Seminar 2.06. Task №01       *");
  puts("*************************************\n");
  int countBooks;
  struct book catalog[lmax], *mostExpensiveBook;
  inputBooks(&countBooks, catalog);
  mostExpensiveBook = findMostExpensive(countBooks, catalog);
  printf("Most expensive book:#%ld\n", mostExpensiveBook - catalog + 1);
  printf("\tAuthor.........: %s\n", mostExpensiveBook->author);
  printf("\tTitle..........: %s\n", mostExpensiveBook->title);
  printf("\tPublishing year: %d\n", mostExpensiveBook->year);
  printf("\tPrice..........: %d\n", mostExpensiveBook->price);
  return 0;
}