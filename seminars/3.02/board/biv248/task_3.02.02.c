#include <malloc.h>
#include <stdio.h>

struct node {
  struct node *next;
  int info;
};

struct node *stack() {  // формирование стека
  int n;
  // p - указатель на текущую добавляемую запись
  // lst - указатель на предыдущую запись (на вершину стека)
  struct node *p, *lst;

  lst = NULL;  // пустой стек
  printf("Enter positive integers:\n");
  while (scanf("%d", &n) == 1 && n > 0) {
    // ввод до Ctrl+Z(D) или n<=0
    p = (struct node *)malloc(sizeof(struct node));
    p->info = n;
    p->next = lst;
    lst = p;
  }
  return (lst);
  // вернет указатель на вершину стека
}

// Поиск минимального из элементов списка
int findMinElementOfList(struct node *lst) {
  int min = lst->info;
  struct node *p = lst->next;
  while (p){
    if (p->info < min){
      min = p->info;
    }
    p=p->next;
  }
  return min;
}

// Вывод списка на экран
void printList(struct node *lst) {
  struct node *p = lst;
  while (p){
    printf("%5d", p->info);
    p=p->next;
  }
}

// Освобождение памяти
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
  puts("*      Seminar 3.02. Task №02       *");
  puts("*************************************\n");
  struct node *lst = stack();
  if (!lst)
    puts("List is empty");
  else {
    puts("Original list:");
    printList(lst);
    printf("\nMin = %7d", findMinElementOfList(lst));
    freeMemory(lst);
  }
  return 0;
}