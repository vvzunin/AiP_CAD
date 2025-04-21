#include <iostream>
using namespace std;

struct node {
  node *next;
  int info;
};

// формирование списка
node *stack() {
  int n = 1;
  node *p, *lst; /* p - указатель на текущую добавляемую запись,
  lst - указатель на предыдущую запись (на вершину стека) */

  lst = NULL;
  cout << "Enter positive integers\n";
  while (n > 0) {
    // ввод до не числа или n<=0
    cin >> n;
    if (!cin.fail() && n > 0) {
      p = new node;
      p->info = n;
      p->next = lst;
      lst = p;
    }
  }
  return lst; /* вернет указатель на вершину стека */
}

void prn(node *lst) {
  node *p = lst;
  while (p) {
    cout << p->info << "  ";
    p = p->next;
  }
  cout << endl;
}

void free_memory(node *lst) { // освобождение памяти
  node *now = lst, *next = lst;
  while (next) {
    next = now->next;
    delete(now);
    now = next;
  }
  cout << "\nNow memory is free" << endl;
}

node* ins(node *lst1, node *lst2) {
  node *curr1 = lst1, *curr2 = lst2, *prev1 = lst1;
  while (curr1 && (curr1->info % 2) != 0) {
    prev1 = curr1;
    curr1 = curr1->next;
  }
  if (!curr1) {
    cout << "First list has no even elements" << endl;
    free_memory(lst1);
    return NULL;
  }

  curr2 = lst2;
  while (curr2->next)
    curr2 = curr2->next;

  if (curr1 == lst1) {
    curr2->next = lst1;
    lst1 = lst2;
  } else {
    curr2->next = curr1;
    prev1->next = lst2;
  }

  return lst1;
}

int main() {
  cout << "*************************************\n";
  cout << "*      Seminar 4.04. Task №02       *\n";
  cout << "*************************************\n\n";

  node *lst1, *lst2;
  cout << "First list:" << endl;
  lst1 = stack();

  if (!lst1) {
    cout << "First list is empty";
  } else {
    cout << "First list:" << endl;
    prn(lst1);

    cout << "Second list:" << endl;
    lst2 = stack();

    if (!lst2) {
      cout << "Second list is empty" << endl;
      cout << "First list:" << endl;
      free_memory(lst1);
    } else {
      cout << "Second list:" << endl;
      prn(lst2);

      lst1 = ins(lst1, lst2);

      if (!lst1) {
        cout << "No insert" << endl;
        cout << "Second list:" << endl;
        free_memory(lst2);
      } else {
        cout << "Changed list:" << endl;
        prn(lst1);
        cout << "First list:" << endl;
        free_memory(lst1);
      }
    }
  }

  return 0;
}
