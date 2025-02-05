#include <iostream>
using namespace std;

int main() {
  cout << "*************************************\n";
  cout << "*      Seminar 3.04. Task №02       *\n";
  cout << "*************************************\n\n";

  int a[10], b[10], c[10], na, nb, nc = 0, i, j, k;

  cout << "Ввелите длину массива а\n";
  cin >> na;
  cout << "Ввелите длину массива b\n";
  cin >> nb;

  cout << "Ввелите массив а\n";
  for (int i = 0; i < na; i++){
    cin >> a[i];
  }

  cout << "Ввелите массив b\n";
  for (int i = 0; i < nb; i++){
    cin >> b[i];
  }

  for (int i = 0; i < na; i++){
    k = 0;
    for (int j = 0; j < nb && k < 2; j++)
      if (a[i] == b[j])
        k++;
    if (k == 2){
      for (int j = 0; j < nc && a[i] != c[j]; j++);
      if (j == nc){
        c[nc] = a[i];
        nc++;
      }
    }
  }
  if (nc == 0)
    cout << "\nмассив с пуст";
  else {
    for (int i = 0; i < nc; i++){
      cout << "\n" << c[i];
    }
  }



  return 0;
}
