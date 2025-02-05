#include <iostream>
using namespace std;

// Прототип функции
int change(int a[][20], int n, int m);

int main() {
  cout << "*************************************\n";
  cout << "*      Seminar 3.04. Task №04       *\n";
  cout << "*************************************\n\n";
  int a[10][20], n, m, i, *j;
  int k;

  cout << "Введите n и m" << endl;
  cin >> n >> m;

  cout << "Введите матрицу" << endl;
  for (i = 0; i < n; i++)
    for (j = a[i]; j < a[i] + m; j++)
      cin >> *j;

  k = change(a, n, m);

  if (k == 0)
    cout << "Нет четных" << endl;
  else if (k == 1)
    cout << "Один четный" << endl;
  else if (k == 2) {
    cout << "В одном столбце" << endl;
    cout << "Матрица не изменилась" << endl;
  } else {
    cout << "Матрица после обмена" << endl;
    for (i = 0; i < n; i++) {
      for (j = a[i]; j < a[i] + m; j++)
        cout << *j << "   ";
      cout << endl;
    }
  }
  return 0;
}

int change(int a[][20], int n, int m) {
  int i, j1, jp, *uj, p, *u1, *up;
  bool k = false;
  u1 = up = NULL;
  for (i=0;i<n;i++){
    for (uj=a[i]; uj<a[i]+m;uj++){
      if (*uj %2==0){
        if (u1 == NULL){
          u1 = uj;
          j1 = uj-a[i];
        }
        up = uj;
        jp = uj-a[i];
      }
    }
  }
  if(u1 == NULL){
    return 0;
  }
  else if(u1 == up){
    return 1;
  }
  else if(j1 == jp){
    return 2;
  }
  else{
    for (u1=a[0]+j1, up=a[0]+jp; u1<a[n-1]+m;u1 = u1 +20, up = up +20){
      p = *u1;
      *u1 = *up;
      *up = p;
    }
    return 3;
  }
}