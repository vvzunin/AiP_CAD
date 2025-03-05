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

bool is_inB(int B[], int k, int target)
{
  for (int *i = B; i - B < k; i++)
    if (*i == target)
      return true;
  return false;
}

int search(int A[][2*N], int B[], int n, int m, int k, int C[]) {
  int C_size = 0;
  for (int *j = A[0]; j - A[0] < n; j++) {
    int *first_chet = nullptr;
    int *max_nechet = nullptr;
    for (int *u = j; u - j < m * 2 * N; u += 2 * N) {
      cout << *u << " ";
      if (*u % 2 == 0) {
        if (!first_chet)
          first_chet = u;
      }
      else {
        if (!max_nechet)
          max_nechet = u;
        else if (*u >= *max_nechet)
          max_nechet = u;
      }
      
    }
    cout << endl;
    cout << "Столбец " << j-A[0] << ": " << *first_chet << ", " << *max_nechet << endl;
    if (!first_chet && !max_nechet) {
      if (first_chet + 2 * N < max_nechet) {
        bool flag = false;
        for (int *u = first_chet + 2 * N; u < max_nechet; u += 2 * N)
          if (!flag)
            flag = is_inB(B, k, *u);
        if (!flag)
          for (int *u = first_chet + 2 * N; u < max_nechet; u += 2 * N)
            C[C_size++] = *u;
      }
      else if (max_nechet + 2 * N < first_chet) {
        bool flag = false;
        for (int *u = max_nechet + 2 * N; u < first_chet; u += 2 * N)
          if (!flag)
            flag = is_inB(B, k, *u);
        if (!flag)
          for (int *u = max_nechet + 2 * N; u < first_chet; u += 2 * N)
            C[C_size++] = *u;
      }
    } 
  }
  return C_size;
}
