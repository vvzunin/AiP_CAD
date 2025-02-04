#include <stdio.h>
#include <stdlib.h>

struct node {
  struct node *next;
  int info;
};

// Функция создания списка
struct node *queue() {
  int n;
  struct node *add, *last, *first = NULL; // Сначала список пуст

  printf("Enter positive integers:\n");
  if (!scanf("%d", &n) || n <= 0)
    return first;
  else {
    first = (struct node *)malloc(sizeof(struct node));
    // выделим память для первой записи
    first->info = n; // занесем число в поле данных
    last = first;    // сделаем эту запись последней
    while (scanf("%d", &n) == 1 && n > 0) {
      // ввод до Ctrl+Z или n<=0
      add = (struct node *)malloc(sizeof(struct node));
      // память для добавляемой записи
      add->info = n;
      last->next = add; // присоединим её к cписку
      last = add;
    } // сделаем эту запись последней
    last->next = NULL; // это последняя запись в списке
    return first;      // вернем адрес начала списка
  }
}

// Функция вывода списка
void printList(struct node *lst) {
  if (!lst)
    puts("List is empty!");
  else {
    while (lst) {
      printf("%7d", lst->info);
      lst = lst->next;
    }
    printf("\n");
  }
}

// Функция вставки 100 перед максимальным и 1000
// после него
struct node *before_and_after(struct node *first) {
  struct node *max = first;
  struct node *predmax = first;
  struct node *pred = first;
  struct node *curr = first->next;
  while (curr) {
    if (curr->info > max->info) {
      max=curr;
      predmax=pred;
    }
    pred=pred->next;
    curr=curr->next;
  }
  
  if (max != first) {
    curr = (struct node *)malloc(sizeof(struct node)); 
    predmax->next = curr;
    curr->next = max;
    curr->info = 100;
  } else {
    curr = (struct node *)malloc(sizeof(struct node)); 
    curr->next = max;
    first = curr;
    curr->info = 100;
  }

  curr = (struct node *)malloc(sizeof(struct node)); 
  curr->next = max->next;
  max->next = curr;
  curr->info = 1000;

  return first;
}

// Функция освобождения памяти
void freeMemory(struct node *lst) {
  struct node *now = lst, *next = lst;
  while (next) {
    next = now->next;
    free(now);
    now = next;
  }
  puts("\nNow memory is free!");
}

int main() {
  puts("*************************************");
  puts("*      Seminar 3.03. Task №01       *");
  puts("*************************************\n");

  struct node *lst;
  lst = queue();

  printf("Initial list:\n");
  printList(lst);

  if (lst) {
    lst = before_and_after(lst);
    printf("Modified list:\n");
    printList(lst);
    freeMemory(lst);
  }

  return 0;
}
