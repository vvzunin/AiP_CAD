#include <iostream>
using namespace std;

struct node2 {
  int info;
  node2 *next, *prev;
};

node2* make() {
  node2 *lst = NULL, *curr = NULL, *t_prev = NULL;
  int n = 1;
  cout << "Enter positive integers:\n";
  while (n > 0) {
    cin >> n;
    if (!cin.fail() && n > 0) {
      curr = new node2;
      curr->info = n;
      if (!lst) {
        lst = curr;
        curr->prev = NULL;
      } else {
        t_prev->next = curr;
        curr->prev = t_prev;
      }
      t_prev = curr;
    }
  }
  if (curr) curr->next = NULL;
  return lst;
}

void output2(node2* lst) {
  node2 *t = lst;
  cout << "\tList ->\n\t\t";
  while (lst) {
    cout << lst->info << "  ";
    t = lst;
    lst = lst->next;
  }

  cout << "\n\tList <-\n\t\t";
  while (t) {
    cout << t->info << "  ";
    t = t->prev;
  }
}

void freeMemory2(node2 *first) {
  node2 *tmp = first;
  while (tmp) {
    tmp = first->next;
    delete first;
    first = tmp;
  }
  cout << "\nMemory is free!\n";
}

node2* modifyList(node2 *lst, bool *f) {
  node2 *curr = lst, *pr = NULL;
  *f = false;

  while (curr && lst) {
    if (curr->info % 2) {
      *f = true;
      if (curr == lst) {
        lst = curr->next;
        if (lst != NULL)
          lst->prev = NULL;
        delete curr;
        curr = lst;
      } else {
        (curr->prev)->next = curr->next;
        if (curr->next)
          (curr->next)->prev = curr->prev;
        pr = curr->next;
        delete curr;
        curr = pr;
      }
    } else {
      curr = curr->next;
    }
  }
  return lst;
}

int main() {
  cout << "*************************************\n";
  cout << "*      Seminar 4.05. Task №02       *\n";
  cout << "*************************************\n\n";
  
  node2 *lst;
  bool f;
  lst = make();

  if (!lst) {
    cout << "Empty list!\n";
  } else {
    cout << "List:\n";
    output2(lst);

    lst = modifyList(lst, &f);

    if (!f)
      cout << "\nNo changes!\n";
    else if (!lst)
      cout << "\nEverything was deleted!\n";
    else {
      cout << "\nNew list:\n";
      output2(lst);
      freeMemory2(lst);
    }
  }
  return 0;
}
