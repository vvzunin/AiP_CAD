#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void check(string filename) {
  fstream f;
  f.open(filename);
  
  if (!f){
    cout << "Error";
    return;
  }

  string s;
  char skobki[100];
  int n = 1;
  skobki[0] = 'q';
  while (!f.eof()){
    getline(f, s);
    cout << s << endl;
    for (int i = 0; i < s.length(); i++){
      if (s[i] == '(' || s[i] == '{')
        skobki[n++] = s[i];
      if (s[i] == ')' ){
        if (skobki[n - 1] == '(')
          n--;
        else{
          cout << "Закрытие круглой скобки после открытия фигурной \n";
          f.close();
          return;
        }
      }
      else if (s[i] == '}'){
        if (skobki[n - 1] == '{')
          n--;
        else{
          cout << "Закрытие фигурной скобки после открытия круглой \n";
          f.close();
          return;
        }
      }
      if (n <= 0){
        cout << "Закрывающихся скобок больше\n";
        f.close();
        return;
      }
    }
  }
  f.close();
  if (n == 1)
    cout << "Файл корректен!\n";
  else 
    cout << "Не все скобки в файле закрыты!\n";
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