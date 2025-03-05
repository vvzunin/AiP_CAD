#include <iostream>
using namespace std;

void new_arr(int na, int A[], int *nb, int B[]) {
  int *ua, *ub = B;
  *nb = 0;
  for (ua = A; ua < A + na; ua++) {
    for (ub = B; ub < B + *nb && *ua != *ub; ub++);
    if (ub == B + *nb) {
      *(ub++) = *ua;
      (*nb)++;
    }
  }
}

int main() {
  cout << "*************************************\n";
  cout << "*      Seminar 3.08. Task №02       *\n";
  cout << "*************************************\n\n";

  int A[20], B[10], na, nb, *up;
  do {
    cout << "Input length of array A: na = ";
    cin >> na;
  } while (na <= 0 || na > 20);

  cout << "Input array A:\n";
  for (up = A; up < A + na; up++)
    cin >> *up;

  new_arr(na, A, &nb, B);

  cout << "Array B:\n";
  for (up = B; up < B + nb; up++)
    cout << *up << " ";

  return 0;
}
