#include <iostream>
using namespace std;

/* структурный тип для односвязного списка */
struct node {
  int info;
  node *next;
};

/* вернет адрес начала полученного списка */
node *make(void) {
  node *lst = NULL, *curr, *first = NULL;
  int n = 1;
  cout << "Enter positive integers\n";

  while (n > 0) { // ввод до не числа или n <= 0
    cin >> n;
    if (!cin.fail() && n > 0) {
      curr = new node;
      if (!lst) first = curr; // если список еще пуст
      curr->next = lst;
      curr->info = n;
      lst = curr;
    }
  }
  if (first) first->next = lst; // зацикливаем
  return first; // вернем адрес последней записи
}

/* вывод циклического списка на экран */
void output(node *lst) {
  node *p;
  p = lst;
  if (lst) {
    do {
      p = p->next;
      cout << p->info << "  ";
    } while (p != lst);
    cout << endl;
  } else {
    cout << "Empty!\n";
  }
}

void del(node *lst) {
  node *cur, *tmp = lst->next;
  cur = lst->next;
  while (tmp != lst) {
    tmp = cur->next;
    delete(cur);
    cur = tmp;
  }
  delete(lst);
  cout << "Everything was deleted!\n";
}

int main() {
  cout << "*************************************\n";
  cout << "*      Seminar 4.04. Task №01       *\n";
  cout << "*************************************\n\n";

  node *lst;
  lst = make();
  output(lst);
  if (lst != NULL)
    del(lst);
  return 0;
}
