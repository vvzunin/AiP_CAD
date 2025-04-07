#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void form(string filename1, string filename2) {
  string s;
  fstream f1;
  f1.open(filename1);
  ofstream f2;
  f2.open(filename2);
  if (f1) {
    cout << "\nFile:\n";
    while (!f1.eof()) {
      getline(f1, s);
      cout << s << endl;
      if (!(s.length() % 2))
        f2 << s << endl;
    }
  }
  f1.close();
  f2.close();
}

int main() {
  cout << "*************************************\n";
  cout << "*      Seminar 4.02. Task №03       *\n";
  cout << "*************************************\n\n";

  string filename1, filename2, s;
  cout << "Input file name with data: ";
  getline(cin, filename1);
  cout << "Input file name for output: ";
  getline(cin, filename2);
  form(filename1, filename2);
  fstream f2;
  f2.open(filename2);
  cout << "\nResult:" << endl;
  getline(f2, s);
  if (!s.length())
    cout << "No such strings!\n";
  else {
    cout << s << endl;
    while (!f2.eof()) {
      getline(f2, s);
      cout << s << endl;
    }
    f2.close();
  }
  return 0;
}