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
  cout << endl;
}

node2* changes(node2 *lst, bool *flag, int x1, int x2) {
  node2 *tek, *nov;
  *flag = false;

  tek = lst;

  if (tek->info > x1 && tek->info < x2) {
    // вставка в начало
    nov = new node2;
    nov->info = 2000;
    nov->next = tek;
    nov->prev = NULL;
    lst = nov;
    tek->prev = nov;
    *flag = true;
  }

  tek = tek->next;
  while (tek) {
    if (tek->info > x1 && tek->info < x2) {
      // вставка в середину
      nov = new node2;
      nov->info = 2000;
      nov->next = tek;
      nov->prev = tek->prev;
      (tek->prev)->next = nov;
      tek->prev = nov;
      *flag = true;
    }
    tek = tek->next;
  }
  return lst;
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
  cout << "*      Seminar 4.04. Task №04       *\n";
  cout << "*************************************\n\n";

  node2 *lst;
  bool flag;
  int x1, x2;

  lst = make();
  if (!lst) {
    cout << "List is empty";
  } else {
    cout << "First list:" << endl;
    output(lst);

    do {
      cout << "\nEnter x1 and x2 (x1 < x2): ";
      cin >> x1 >> x2;
    } while (x2 <= x1 + 1);

    lst = changes(lst, &flag, x1, x2);

    if (!flag) {
      cout << "\nNo changes!\n";
    } else {
      cout << "\nNew list:" << endl;
      output(lst);
    }
    freemem(lst);
  }

  return 0;
}
