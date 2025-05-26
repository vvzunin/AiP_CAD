#include <iostream>
using namespace std;

struct node {
  int info;
  node *left, *right;
};

node *newtree(int A[], int na) {
  node *der = NULL, *curr, *next, *newc;
  int i;
  for (i = 0; i < na; i++) {
    newc = new node;
    newc->info = A[i];
    newc->left = newc->right = NULL;
    if (!der) der = newc;
    else {
      curr = next = der;
      while (next) {
        curr = next;
        if (newc->info < curr->info)
          next = curr->left;
        else
          next = curr->right;
      }
      if (newc->info < curr->info)
        curr->left = newc;
      else
        curr->right = newc;
    }
  }
  return der;
}

void printTree(node *der, int h) {
  if (der) {
    printTree(der->left, h + 1);
    for (int i = 0; i < h; i++)
      cout << "  ";
    cout << der->info << endl;
    printTree(der->right, h + 1);
  }
}

int *ua;

void search(node *der) {
  if (!der) return;
  search(der->left);
  *ua = der->info;
  ua++;
  search(der->right);
}

void sort(node *der, int a[], int na) {
  ua = a;
  search(der);
}

int main() {
  cout << "*************************************\n";
  cout << "*      Seminar 4.08. Task №01       *\n";
  cout << "*************************************\n\n";

  node *der;
  int na, a[50];
  cout << "Input size of array:" << endl;
  cin >> na;
  cout << "Input array:" << endl;
  for (int i = 0; i < na; i++)
    cin >> a[i];
  cout << "We are making a tree..." << endl;
  der = newtree(a, na);
  if (!der)
    cout << "No tree!\n";
  else {
    cout << "Tree:" << endl;
    printTree(der, 0);
    sort(der, a, na);
    cout << "Array after sort:" << endl;
    for (int i = 0; i < na; i++)
      cout << a[i] << "   ";
    cout << endl;
  }
  return 0;
}

// Второй вариант

node *add(node *tree, int info) {
  if (!tree) {
    tree = new node;
    tree->left = NULL;
    tree->right = NULL;
    tree->info = info;
    return tree;
  }
  if (info < tree->info)
    tree->left = add(tree->left, info);
  else
    tree->right = add(tree->right, info);
  return tree;
}

node *create(int ar[], int n) {
  node *tree = NULL;
  for (int i = 0; i < n; i++)
    tree = add(tree, ar[i]);
  return tree;
}
