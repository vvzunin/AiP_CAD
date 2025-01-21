#include <malloc.h>
#include <stdio.h>

struct node {
  struct node *next;
  int info;
};

// Формирование очереди. Возврат указателя на первую запись
struct node *queue() {
  int n;  struct node *add,*last, *first=NULL; // Сначала список пуст
  printf("Enter positive integers:\n");
  if(!scanf("%d",&n)||n<=0)
    return  first;
  else {
    first= (struct node*) malloc(sizeof(struct node)); 
    //выделим память для первой записи
    first->info=n; //занесем число в поле данных
    last=first; //сделаем эту запись последней
    while(scanf("%d",&n)==1&&n>0) { //ввод до Ctrl+Z или n<=0
      add= (struct node*) malloc(sizeof(struct node)); 
      //память для добавляемой записи
      add->info=n;  last->next=add; //присоединим её к cписку
      last=add;
    } //сделаем эту запись последней
    last->next=NULL; //это последняя запись в списке
    return(first); //вернем адрес начала списка
  }
}

// Вывод списка на экран
void printList(struct node *lst) {
  if(!lst)
    puts ("List is empty!");
  else {
    while(lst) {
      printf("%7d", lst->info);
      lst=lst->next;
    }
    printf("\n");
  }
}

// Аргументы: 
//    lst - начало списка,
//    flag - признак его изменения.
// Возвращает адрес начала измененного списка
struct node *del(struct node *lst, int *flag) {
  struct node *curr, *pred;
  *flag = 0;
  curr = pred = lst;
  while (curr)
    if ((curr->info) % 2) { // удаляем
      if (curr == lst) { // первый
        curr = curr->next;
        free(lst);
        lst = curr;
        pred = curr;
      }
      else { // не первый
        pred->next = curr->next;
        free(curr);
        curr = pred->next;
      }
      *flag = 1;
    }
    else { // не удаляем – движение по списку
      pred = curr;
      curr = curr->next;
    }
  return lst;
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
  puts("*      Seminar 3.02. Task №03       *");
  puts("*************************************\n");
  struct node *lst;
  int flag = 0;
  lst = queue();
  printList(lst);
  if (lst) {
    lst = del(lst, &flag);
    if (flag) {
      printf("Changed list:\n");
      printList(lst);
    }
    else
      printf("No changes in list:\n");
    freeMemory(lst);
  }
  return 0;
}