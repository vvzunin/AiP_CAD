#include <iostream>
using namespace std;

bool sort(int A[][20], int n, int m, int B[], int k) {
  int i, *uj, *ui, c, *ut;
  bool flag, flag_ch = false;

  for (i = 0; i < n; i++) {
    flag = true;
    for (ui = A[i]; ui < A[i] + m && flag; ui++) {
      for (uj = B; uj < B + k && *ui != *uj; uj++);
      if (uj == B + k)
        flag = false;
    }
    if (flag) {
      for (uj = A[i]; uj < A[i] + m - 1; uj++)
        for (ut = uj + 1; ut < A[i] + m; ut++)
          if (*uj > *ut) {
            c = *ut;
            *ut = *uj;
            *uj = c;
            flag_ch = true;
          }
    }
  }
  return flag_ch;
}

int main() {
  cout << "*************************************\n";
  cout << "*      Seminar 3.06. Task №03       *\n";
  cout << "*************************************\n\n";

  int A[10][20], n, m, i, j, B[10], k;
  do {
    cout << "Введите размерность матрицы";
    cout << "(0 < n, m <= 10):\n";
    cin >> n >> m;
  } while (n > 10 || n <= 0 || m > 20 || m <= 0);

  cout << "Введите матрицу A: \n";
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      cin >> A[i][j];

  do {
    cout << "Введите размерность массива"; 
    cout << "(0 < k <= 10): \n";
    cin >> k;
  } while (k > 10 || k <= 0);

  cout << "Введите массив B:\n";
  for (i = 0; i < k; i++)
    cin >> B[i];

  if (sort(A, n, m, B, k)) {
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++)
        cout << A[i][j] << " ";
      cout << endl;
    }
  } else
    cout << "Сортировки не было!\n";

  return 0;
}
