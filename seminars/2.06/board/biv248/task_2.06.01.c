#include <stdio.h>

#define lmax 200
// пропуск символов до конца строки
#define CLR while (getchar() != '\n')

struct book {
  char author[20], title[60];
  int year, price;
};

// Функция ввода массива структур (каталога)
int inputBooks(struct book book_array[]) {
  int n = 0;
  char ch;
  do {
    printf("Book #%d\n", n++);
    printf("Autor:");
    gets(book_array->author);
    printf("Title:");
    gets(book_array->title);
    printf("Year of publishing:");
    scanf("%d",&book_array->year);
    printf("price:");
    CLR;
    scanf("%d",&book_array->price);
    printf("continue? (y/n)");
    CLR;
    ch = getchar();
    CLR;
    book_array++;
  } while (ch=='y' && n < lmax);
  return n;
}



// Функция поиска самой дорогой книги
struct book *findMostExpensive(int n, struct book books[]) {
  struct book *a = books++;
  for (int i = 1; i < n; i++, books++) {
    if(books->price > a->price) {
      a = books;
    }
  }
  return a;
}

int main() {
  puts("*************************************");
  puts("*      Seminar 2.06. Task №01       *");
  puts("*************************************\n");
  struct book books[lmax];
  int n = inputBooks(books);
  struct book *maxprice = findMostExpensive(n, books);
  printf("Book #%d\n",(maxprice-books));
  printf("\tAutor: %s\n", maxprice->author);
  printf("\tTitle: %s\n", maxprice->title);
  printf("\tYear of publishing: %d\n" ,maxprice->year);
  printf("\tPrice: %d\n", maxprice->price);
  return 0;
}