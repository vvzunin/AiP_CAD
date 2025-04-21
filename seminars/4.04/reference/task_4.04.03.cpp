#include <iostream>
using namespace std;

struct node2 {
  int info;
  node2 *next, *prev;
};

node2* make(void) {
  node2 *lst = NULL, *curr = NULL, *t_prev = NULL;
  int n = 1;
  cout << "Enter positive integers\n";

  while (n > 0) {
    cin >> n;
    if (!cin.fail() && n > 0) {
      curr = new node2;
      curr->info = n;

      if (!lst) { // списка еще нет
        lst = curr;
        curr->prev = NULL;
      } else { // не первый элемент
        t_prev->next = curr;
        curr->prev = t_prev;
      }
      t_prev = curr;
    }
  }

  if (curr) curr->next = NULL;
  return lst;
}

/* вывод списка на экран в прямом и обратном направлении */
void output(node2 *lst) {
  node2 *t = lst;
  cout << "List ->" << endl;
  while (lst) {
    cout << lst->info << "  ";
    t = lst;
    lst = lst->next;
  }

  cout << "\nList <-" << endl;
  while (t) {
    cout << t->info << "  ";
    t = t->prev;
  }
}

void freemem(node2 *first) {
  node2 *tmp = first;
  while (tmp) {
    tmp = first->next;
    delete first;
    first = tmp;
  }
  cout << "\nMemory is free" << endl;
}

int main() {
  cout << "*************************************\n";
  cout << "*      Seminar 4.04. Task №03       *\n";
  cout << "*************************************\n\n";

  node2 *lst = make();
  output(lst);
  freemem(lst);
  return 0;
}
