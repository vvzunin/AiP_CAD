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
  node *s1 = lst1;
  node *pred = NULL;
  while (s1 && ((s1->info) % 2) != 0){
    pred = s1;
    s1 = s1->next;
  }
  if (s1 == NULL){
    free_memory(lst1);
    return NULL;
  }

  node *s2 =lst2;
  while (s2->next){
    s2 = s2->next;
  }
  if (pred == NULL){
    s2->next = lst1;
    return lst2;
  }
  else{
    pred->next = lst2;
    s2->next = s1;
    return lst1;
  }
  
  return NULL;
}

int main() {
  cout << "*************************************\n";
  cout << "*      Seminar 4.04. Task №02       *\n";
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
        cout << "No insert!" << endl;
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
