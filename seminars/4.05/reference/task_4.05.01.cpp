#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct node {
  int info;
  node *next;
};

node* list() {
  node *lst = NULL, *prev, *cur = NULL;
  int k = 1;
  cout << "Input elements, letter is end of input:\n";

  while (k) {
    cin >> k;
    if (cin.fail())
      k = 0;
    else if (k) {
      cur = new node;
      cur->info = k;
      if (lst == NULL) {
        lst = cur;
        prev = cur;
      } else {
        prev->next = cur;
        prev = cur;
      }
    }
  }

  if (cur) cur->next = lst;
  cin.clear();
  return cur;
}

void printQueue(node *lst) {
  node *cur = lst;
  if (cur == NULL) {
    cout << "No queue!\n";
  } else {
    do {
      cur = cur->next;
      cout << cur->info << "   ";
    } while (cur != lst);
    cout << endl;
  }
}

node* updateQueue(node *lst, int *flag) {
  int x1, x2, f = 0;
  string s;

  do {
    do {
      getline(cin, s);
      f = 0;
      cout << "x1 = ";
      cin >> x1;
      if (cin.fail()) {
        f = 1;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
    } while (f);

    do {
      getline(cin, s);
      f = 0;
      cout << "x2 = ";
      cin >> x2;
      if (cin.fail()) {
        f = 1;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
    } while (f);

    if (x1 >= x2)
      cout << "\nx1 >= x2! Please repeat.\n";
  } while (x1 >= x2);

  node *curr = lst;
  node *currn = lst->next;

  while (currn != lst) {
    if (currn->info > x2 || currn->info < x1) {
      *flag = 1;
      curr->next = currn->next;
      delete currn;
      currn = curr;
    }
    curr = currn;
    currn = currn->next;
  }

  if (currn->info > x2 || currn->info < x1) {
    *flag = 1;
    curr->next = currn->next;
    lst = (lst->next != lst) ? curr : NULL;
    delete currn;
  }

  return lst;
}

void freeMemory(node *lst) {
  node *now = lst->next, *next = NULL;
  if (lst->next == lst)
    delete lst;
  else {
    while (next != lst) {
      next = now->next;
      delete now;
      now = next;
    }
    delete next;
  }
  cout << "\nNow memory is free!\n";
}

int main() {
  cout << "*************************************\n";
  cout << "*      Seminar 4.05. Task №01       *\n";
  cout << "*************************************\n\n";

  node *lst = list();
  int flag = 0;

  cout << "Original list:\n";
  printQueue(lst);

  if (lst) {
    lst = updateQueue(lst, &flag);
    if (!flag)
      cout << "No changes!\n";
    else {
      cout << "Changed list:\n";
      printQueue(lst);
    }
    if (lst)
      freeMemory(lst);
  }

  return 0;
}
