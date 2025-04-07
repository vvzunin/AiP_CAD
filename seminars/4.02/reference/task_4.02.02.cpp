#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void check(string filename) {
  int nopen1, nclose1, nopen2, nclose2;
  nopen1 = nclose1 = nopen2 = nclose2 = 0;
  // число открытых и закрытых фигурных и круглых скобок
  bool more1 = true, more2 = true;
  // флаги – закрытая скобка не предшествует открытой
  string s;
  fstream f;
  f.open(filename);
  if (f) {
    cout << "File:\n";
    while (!f.eof() && more1 && more2) {
      getline(f, s);
      cout << s << endl;
      for (int i = 0; i < s.length() && more1 && more2; i++) {
        switch (s[i]) {
          case '{':
            nopen1++;
            break;
          case '}':
            nclose1++;
            break;
          case '(':
            nopen2++;
            break;
          case ')':
            nclose2++;
            break;
        }
        if (nclose1 > nopen1) {
          cout << "} before{" << endl;
          more1 = false;
        }
        if (nclose2 > nopen2) {
          cout << ") before(" << endl;
          more2 = false;
        }
      }
    }
    f.close();
    if (more1 && more2) {
      if (nclose1 != nopen1)
        cout << "No balance in {}" << endl;
      if (nclose2 != nopen2)
        cout << "No balance in ()" << endl;
      if (nclose1 == nopen1 && nclose2 == nopen2)
        cout << "Balance in all" << endl;
    }
  } else
    cout << "File not found!" << endl;
}

int main() {
  cout << "*************************************\n";
  cout << "*      Seminar 4.02. Task №02       *\n";
  cout << "*************************************\n\n";

  string filename;
  cout << "Input file name: ";
  getline(cin, filename);

  check(filename);
  return 0;
}