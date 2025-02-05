#include <iostream>
using namespace std;

// Прототип функции
bool change(int a[][20], int n, int m);

int main() {
  cout << "*************************************\n";
  cout << "*      Seminar 3.04. Task №04       *\n";
  cout << "*************************************\n\n";
  int a[10][20], n, m, i, *j;
  bool k;

  cout << "Введите n и m" << endl;
  cin >> n >> m;

  cout << "Введите матрицу" << endl;
  for (i = 0; i < n; i++)
    for (j = a[i]; j < a[i] + m; j++)
      cin >> *j;

  k = change(a, n, m);

  if (!k)
    cout << "Матрица не изменилась" << endl;
  else {
    cout << "Матрица после обмена" << endl;
    for (i = 0; i < n; i++) {
      for (j = a[i]; j < a[i] + m; j++)
        cout << *j << "   ";
      cout << endl;
    }
  }
  return 0;
}

bool change(int a[][20], int n, int m) {
  int i, j1, jp, *uj, p, *u1, *up;
  bool k = false;
  u1 = up = NULL;

  for (i = 0; i < n; i++)
    for (uj = a[i]; uj < a[i] + m; uj++) {
      if (*uj % 2 == 0) {
        if (u1 == NULL) {
          u1 = uj;
          j1 = uj - a[i];
        }
        up = uj;
        jp = uj - a[i];
      }
    }
  if (u1 == NULL)
    cout << "Нет четных" << endl;
  else if (u1 == up)
    cout << "Один четный" << endl;
  else if (j1 == jp)
    cout << "В одном столбце" << endl;
  else {
    k = true;
    for ( u1 = a[0] + j1, up = a[0] + jp;
          u1 < a[n - 1] + m;
          u1 += 20, up += 20) {
      p = *u1;
      *u1 = *up;
      *up = p;
    }
  }
  return k;
}