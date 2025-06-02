#include <iostream>
using namespace std;

void insertionSort(int list[], int listLength) {
  for (int i = 1; i < listLength; i++) {
    int j = i - 1;

    while (j >= 0 && list[j] > list[j + 1]) {
      swap(list[j], list[j + 1]);
      j--;
    }
  }
}

int main() {
  cout << "*************************************\n";
  cout << "*      Seminar 4.10. Task №01       *\n";
  cout << "*************************************\n\n";

  int list[6] = {3, 19, 48, 0, 6, 4};
  cout << "Original array:\n";
  for (int i = 0; i < 6; i++)
    cout << list[i] << "\t";
  cout << "\n";
  insertionSort(list, 6);
  cout << "\n\nSorted array:\n";
  for (int i = 0; i < 6; i++)
    cout << list[i] << "\t";
  return 0;
}
