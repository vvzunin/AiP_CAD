#include <iostream>
using namespace std;

void mins(int A[][20], int n, int m, int *min[]) {
  int i, *uj;
  for (i = 0; i < n; i++)
    for (uj = A[i], min[i] = NULL; uj < A[i] + m; uj++)
      if (*uj % 2 == 0)
        if (!(min[i]) || *uj < *min[i])
          min[i] = uj;
}

int main() {
  cout << "*************************************\n";
  cout << "*      Seminar 3.06. Task №02       *\n";
  cout << "*************************************\n\n";

  int A[10][20], n, m, i, *uj, *min[10];
  
  cout << "Введите n и m" << endl;
  cin >> n >> m;
  cout << "Введите матрицу" << endl;
  for (i = 0; i < n; i++)
    for (uj = A[i]; uj < A[i] + m; uj++)
      cin >> *uj;

  mins(A, n, m, min);

  for (i = 0; i < n; i++) {
    if (min[i])
      cout << "В строке " << i << " минимум равен " << *min[i] << ".\n";
    else
      cout << "В строке " << i << " нет четных чисел!" << endl;
  }
  return 0;
}
