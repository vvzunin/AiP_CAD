#include <iostream>
using namespace std;

int main() {
  cout << "*************************************\n";
  cout << "*      Seminar 3.09. Task №01       *\n";
  cout << "*************************************\n\n";

  int A[20][20], *u1, *u2, *t, n, m, j, i, c;
  cout << "Введите n: "; cin >> n;
  cout << "Введите m: "; cin >> m;
  cout << "Введите матрицу " << n << " на " << m << " элементов:\n";
  
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      cin >> A[i][j];
  
  // Код здесь
  u1 = u2 = NULL;
  for (i = 0; i < n; i++){
    for (j = 0; j < m; j++){
        if (u1 == NULL){
          u1 = &A[i][j];
        }
        else if (*u1 >= A[i][j]){
          u2 = u1;
          u1 = &A[i][j];
        }
        else if (u2 == NULL || *u2 > A[i][j]){
          u2 = &A[i][j];
        }
    }
  }  
  
  if (!u2 || *u1 == *u2)
    cout << "Нет обмена!\n";
  else {
    // Обмен здесь
    c = *u1;
    *u1 = *u2;
    *u2 = c;
    cout << "Новая матрица:\n";
    
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++)
        cout << A[i][j] << " ";
      cout << endl;
    }
  }
  
  return 0;
}
