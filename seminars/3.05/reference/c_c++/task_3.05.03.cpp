#include <iostream>
using namespace std;

int change(int A[][20], int n, int m); // Прототип

void inputMatrix(int A[][20], int &n, int &m) {
  int i, *j;
  cout << "Введите n и m: " << endl;
  cin >> n >> m;
  cout << "Введите матрицу: " << endl;
  for (i = 0; i < n; i++)
    for (j = A[i]; j < A[i] + m; j++)
      cin >> *j;
}

void outputMatrix(int A[][20], int n, int m) {
  int i, *j;
  for (i = 0; i < n; i++) {
    for (j = A[i]; j < A[i] + m; j++)
      cout << *j << "   ";
    cout << endl;
  }
}

int main() {
  cout << "*************************************\n";
  cout << "*      Seminar 3.05. Task №03       *\n";
  cout << "*************************************\n\n";

  int A[10][20], n, m, i, *j;
  int k;
  inputMatrix(A, n, m); // Передача параметров по ссылке

  cout << "Исходная матрица:\n";
  outputMatrix(A, n, m);
  k = change(A, n, m);

  if (k == 1)
    cout << "Матрица не изменилась! Нет четных чисел!\n";
  else if (k == 2)
    cout << "Матрица не изменилась! Одно четное число!\n";
  else if (k == 3)
    cout << "Матрица не изменилась! Четные числа в одном столбце!\n";
  else {
    cout << "Матрица после обмена: " << endl;
    outputMatrix(A, n, m);
  }
  return 0;
}

int change(int A[][20], int n, int m) {
  int i, j1, jp, *uj, p, *u1 = NULL, *up = NULL;

  for (i = 0; i < n; i++)
    for (uj = A[i]; uj < A[i] + m; uj++)
      if (*uj % 2 == 0) {
        if (u1 == NULL) {
          u1 = uj;
          j1 = uj - A[i];
        }
        up = uj;
        jp = uj - A[i];
      }

  if (u1 == NULL)
    return 1;
  else if (u1 == up)
    return 2;
  else if (j1 == jp)
    return 3;
  else {
    for (u1 = A[0] + j1, up = A[0] + jp;
         u1 < A[n - 1] + m;
         u1 += 20, up += 20) {
      p = *u1;
      *u1 = *up;
      *up = p;
    }
  }
  return 0;
}
