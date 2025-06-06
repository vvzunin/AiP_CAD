#include <iostream>
using namespace std;

struct node {
  int info;
  node *left, *right;
};

void printTree(node *der, int h) {
  if (der) {
    printTree(der->left, h + 1);
    for (int i = 0; i < h; i++)
      cout << "  ";
    cout << der->info << endl;
    printTree(der->right, h + 1);
  }
}

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


node *create(int A[], int n) {
  node *tree = NULL;
  for (int i = 0; i < n; i++)
    tree = add(tree, A[i]);
  return tree;
}

bool fl = false;

void udalx(node **tree, int x) {
  node *ader, *curr, *next;
  if (!(*tree)) return;
  while ((ader = *tree) && (ader->info == x)) {
    fl = true;
    if (!ader->right)
      *tree = ader->left;
    else {
      *tree = ader->right;
      if (ader->left) {
        curr = next = *tree;
        while (next) {
          curr = next;
          next = next->left;
        }
        curr->left = ader->left;
      }
    }
    delete(ader);
  }

  if (*tree) {
    if ((*tree)->info > x)
      udalx(&(*tree)->left, x);
    else
      udalx(&(*tree)->right, x);
  }
}

int main() {
  cout << "*************************************\n";
  cout << "*      Seminar 4.08. Task №02       *\n";
  cout << "*************************************\n\n";

  int n;
  node *tree;
  cout << "Input an array length";
  cin >> n;
  int ar[n];
  cout << "Enter array" << endl;
  for (int i = 0; i < n; i++)
    cin >> ar[i];

  tree = create(ar, n);
  if (!tree)
    cout << "Tree is empty!\n";
  else {
    cout << "Original tree:\n";
    printTree(tree, 0);
    int x;
    cout << "Enter x: ";
    cin >> x;
    udalx(&tree, x);
    if (!tree)
      cout << "Tree is empty!\n";
    else {
      if (!fl)
        cout << "Tree was not changed!\n";
      else {
        cout << "New tree:\n";
        printTree(tree, 0);
      }
    }
  }
  return 0;
}
