#include <iostream>
using namespace std;

int change(int **A, int n, int m); // Прототип

void inputMatrix(int** A, int &n, int &m) {
  int i, *j;
  cout << "Введите n и m: " << endl;
  cin >> n >> m;
  cout << "Введите матрицу: " << endl;
  for (i = 0; i < n; i++)
    for (j = A[i]; j < A[i] + m; j++)
      cin >> *j;
}

void outputMatrix(int** A, int n, int m) {
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

  int **A, n, m, i, *j;
  int k;

  A = (int**)malloc(sizeof(int) * 10);
  for(int i = 0; i < 20; ++i) A[i] = (int*)malloc(sizeof(int) * 20);
  
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

  free(A);

  return 0;
}

int change(int** A, int n, int m) {
  int k = 0;
  int *firstEven = NULL, *lastEven = NULL;
  for(int** i = A; i < A + n; ++i) {
    for(int* j = *i; j < *i + m; ++j) {
      if(!firstEven && *j % 2 == 0) firstEven = j;
      if(*j % 2 == 0)               lastEven = j; 
    }
  }

  if(!firstEven || !lastEven) return 1;
  else if(firstEven == lastEven) return 2;

  int columnFirst = (firstEven - *A) % 20;
  int columnLast  = (lastEven  - *A) % 20;
  if(columnFirst == columnLast) return 3;

  for(int** i = A; i < A + n; ++i) {
    int temp = *i[columnFirst];
    *i[columnFirst] = *i[columnLast];
    *i[columnLast] = temp;
  }

  return 0;
}
