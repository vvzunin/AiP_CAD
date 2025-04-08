#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void form(string filename1, string filename2) {
  fstream f1;
  ofstream f2;
  f1.open(filename1);
  if (!f1){
    cout<<"error, file f1 not found"<<endl;
    return;
  }
  f2.open(filename2);
  if (!f2){
    cout<<"error, could not create f2"<<endl;
    return;
  }
  string s;
  while (!f1.eof()){
    getline(f1, s);
    if (s.length()%2==0){
      f2 << s <<endl;
    }
  }
  f1.close();
  f2.close();
}

int main() {
  cout << "*************************************\n";
  cout << "*      Seminar 4.02. Task №03       *\n";
  cout << "*************************************\n\n";
  cout << "Enter input file name: ";
  string s1;
  cin >> s1;
  cout << "Enter output file name: ";
  string s2;
  cin >> s2;
  form (s1, s2);
  cout << "New file created" << endl;

  return 0;
}