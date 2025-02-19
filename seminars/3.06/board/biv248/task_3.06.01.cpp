#include <iostream>
using namespace std;

void search(int A[], int n, int **u2, int **u5) {
  int count = 0;
  *u2 = NULL;
  *u5 = NULL;
  for (int *el = A; el < A + n && count != 5; el++) {
    if (*el % 2 == 0) {
      count++;
      if (count == 2) {
        *u2 = el;
      }
      if (count == 5) {
        *u5 = el;
      }
    }
  }
}

void change(int *u2, int *u5) {
  int temp = *u5;
  *u5 = *u2;
  *u2 = temp;
}

int main() {
  cout << "*************************************\n";
  cout << "*      Seminar 3.06. Task №01       *\n";
  cout << "*************************************\n\n";

  int A[20], n = -1, *u2, *u5;
  do {
    cout << "Input the length of array 0 < n <= 20: ";
    cin >> n;
  } while (n > 20 || n <= 0);

  cout << "Input elements: \n";
  for (int i = 0; i < n; i++)
    cin >> A[i];

  search(A, n, &u2, &u5);

  if (u2 == NULL)
    cout << "No 2 even elements in array\n";
  else if (u5 == NULL)
    cout << "No 5 even elements in array\n";
  else {
    cout << "Address of the second = " << u2 << " element = " << *u2 << endl;
    cout << "\nAddress of the fifth = " << u5 << " element = " << *u5 << endl;
    change(u2, u5);
    cout << "\nArray after changes:\n";
    for (int i = 0; i < n; i++) cout << A[i] << "  ";
    cout << endl;
  }
  return 0;
}
