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
  int x, *i, *j;
  i = A;
  while (i < A + na) {
    for (j = A; j < (A + na) && (*i != *j || i == j); j++);
    if (j < A + na) {
      int *stay = j; /* Указатель на позицию, 
      куда копируем остающийся элемент */
      x = *i; // Запоминаем удаляемый элемент
      for (j = i; j < A + na; j++)
        if (*j != x)
          *stay = *j, stay++;
      na = (stay - A);
    } else i++;
  }
}