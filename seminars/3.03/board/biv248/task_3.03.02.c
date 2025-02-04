#include <stdio.h>
#include <stdlib.h>

struct node
{
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

// Функция реверса списка
struct node *reverse(struct node *lst) {
  struct node* tail, *newhead;
  if (lst == NULL || lst->next == NULL){
    return lst;
  } else {
    tail = lst->next;
    newhead = reverse(tail);
    lst->next = NULL;
    tail->next = lst;
    return newhead;
  }
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
  puts("*      Seminar 3.03. Task №02       *");
  puts("*************************************\n");

  struct node *lst;
  lst = queue();

  printf("Initial list:\n");
  printList(lst);

  if (lst) {
    lst = reverse(lst);
    printf("Reversed list:\n");
    printList(lst);
    freeMemory(lst);
  }

  return 0;
}