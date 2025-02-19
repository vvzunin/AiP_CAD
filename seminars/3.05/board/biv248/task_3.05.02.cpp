#include <iostream>
using namespace std;

// Прототип функции удаления
void del(int &n, int A[]);

int main() {
  cout << "*************************************\n";
  cout << "*      Seminar 3.05. Task №02       *\n";
  cout << "*************************************\n\n";

  int A[50], n, i, n_original;
  cout << "Input 0 < n <= 50: ";
  cin >> n;
  cout << "Input " << n << " elements \n";
  for (i = 0; i < n; i++) 
    cin >> *(A + i);
  n_original = n;

  // Вызов функции, передача параметра по ссылке
  del(n, A);
  
  if (!n) 
    cout << "Array is empty\n";
  else if (n == n_original)
    cout << "Array was not changed\n";
  else {
    cout << "Changed array:\n";
    for (i = 0; i < n; i++) cout << "  " << *(A + i);
    cout << " \n";
  }
  return 0;
}

void del(int &na, int A[]) {
  int *i = A, cur;
  while (i < (A + na)) {
    int *j;
    for (j = A; j < (na + A) && (i == j || *i != *j); j++);
    if (j != na + A) {
      int *k = A;
      cur = *i;
      for (int *l = A; l < na + A; l++ )
        if (*l != cur) {
          *k = *l;
          k++;
        }
      na = k - A;
    }
    i++;
  }
}