#include <iostream>
using namespace std;
struct node {
  node *next;
  int info;
};

node *stack() {
  int n = 1;
  node *p, *lst = nullptr;
  cout << "Enter positive integers\n";
  while (n > 0) {
    cin >> n;
    if (!cin.fail() && n > 0) {
      p = new node;
      p->info = n;
      p->next = lst;
      lst = p;
    }
  }
  return lst;
}

void printList(node *lst) {
  node *p = lst;
  while (p) {
    cout << p->info << "  ";
    p = p->next;
  }
}

void freeMemory(node *lst) {
  node *now = lst, *next = lst;
  while (next) {
    next = now->next;
    delete (now);
    now = next;
  }
  cout << "\nNow memory is free\n";
}

node *newlist(node *lst1) {
  bool f = true;
  node *lst2 = nullptr, *first = lst1;
  while(first) {
    int cnt = 0;
    node *t = lst1;
    while(t && (cnt < 2)){
      t = t->next;
      if (t->info == first->info){
        cnt++;
      }
    }

    if((t == nullptr) && (cnt == 2)){
      node *p = new node;
      p->info = t->info;
      p->next = lst2;
      lst2 = p;
    }

    first = first->next;
  }
  return lst2;
}

// node *newlist(node *lst1) {
//   node *lst2 = nullptr, *first = lst1;
//   while(first){
//     node *t = lst2;
//     bool f = true;
//     while(t && (t->info != first->info || t == first) &&
//           ((t->info != first->info && t != first) || f)){

//       t = t->next;
//       if (t->info == first->info && t != first){
//         f = false;
//       }
//     }

//     if(t != nullptr){

//       node *p = new node;
//       p->info = t->info;
//       p->next = lst1;
//       lst2 = p;
//     }

//     first = first->next;
//   }
//   return lst2;
// }

int main() {
  cout << "*************************************\n";
  cout << "*      Seminar 4.06. Task №03       *\n";
  cout << "*************************************\n\n";
  node *lst1, *lst2;
  cout << "Input data for original stack\n";
  lst1 = stack();
  if (lst1) {
    cout << "Original list:\n";
    printList(lst1);
    lst2 = newlist(lst1);
    if (!lst2)
      cout << "\nNo new list!\n";
    else {
      cout << "\nNew list:\n";
      printList(lst2);
      cout << "\nNew list: ";
      freeMemory(lst2);
    }
    cout << "\nOriginal list: ";
    freeMemory(lst1);
  }
  else
    cout << "\nNo original list!\n";
  return 0;
}
