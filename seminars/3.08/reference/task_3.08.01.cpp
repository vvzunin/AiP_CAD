#include <iostream>
#define N 100
using namespace std;

// Прототипы функций
void input(int A[][2*N], int B[], int *n, int *m, int *k);
void output(int C[], int p);
int search(int A[][2*N], int B[], int n, int m, int k, int C[]);

// Проверка правильности ввода длины
void check(int *r, char name) {
  do {
    cout << "Input " << name << ": ";
    cin >> *r;
  } while (*r < 0 || *r > N);
}

int main() {
  cout << "*************************************\n";
  cout << "*      Seminar 3.08. Task №01       *\n";
  cout << "*************************************\n\n";

  int A[N][2*N], B[N], C[N], n, m, k, p = 0;
  input(A, B, &n, &m, &k);
  p = search(A, B, n, m, k, C);
  output(C, p);
  return 0;
}

void input(int A[][2*N], int B[], int *n, int *m, int *k) {
  cout << "Input matrix size.\n";
  check(n, 'n');
  check(m, 'm');

  cout << "Input matrix:\n";
  for (int i = 0; i < *n; i++)
    for (int j = 0; j < *m; j++)
      cin >> A[i][j];

  cout << "Input array size.\n";
  check(k, 'k');

  cout << "Input array:\n";
  for (int i = 0; i < *k; i++)
    cin >> B[i];
}

void output(int C[], int p) {
  if (!p) {
    cout << "There are no suitable elements!\n";
  } else {
    cout << "Result:\n";
    for (int i = 0; i < p; i++)
      cout << "   " << C[i];
    cout << endl;
  }
}

int search(int A[][2*N], int B[], int n, int m, int k, int C[]) {
  int p = 0;

  for (int j = 0; j < m; j++) { // Индексы
    int first_ch = -1, max_nc = -1;

    for (int i = 0; i < n; i++) {
      if (A[i][j] % 2 == 0 && first_ch == -1)
        first_ch = i;

      if (A[i][j] % 2 != 0)
        if (max_nc == -1 || A[i][j] > A[max_nc][j])
          max_nc = i;
    }

    int pr = 0;
    if (first_ch == -1) {
      cout << "No even elements in column " << j << endl;
      pr = 1;
    } else if (max_nc == -1) {
      cout << "No odd elements in column " << j << endl;
      pr = 1;
    } else if (first_ch > max_nc)
      swap(first_ch, max_nc); // Перестановка индексов

    if (first_ch == max_nc - 1) {
      cout << "Can't be done in column " << j << endl;
      pr = 1;
    }

    if (pr == 0) {
      bool flag = false;
      for (int r = first_ch + 1; r < max_nc 
          && flag == false; r++) {
        for (int g = 0; g < k; g++)
          if (B[g] == A[r][j]) // Если элемент найден в B
            flag = true;
      }

      if (flag == false)
        for (int e = first_ch + 1; e < max_nc; e++)
          C[p++] = A[e][j];
    }
  }
  return p;
}
