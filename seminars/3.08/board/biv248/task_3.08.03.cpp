#include <string>
#include <iostream>
#include <ctype.h>
using namespace std;

int main() {
  cout << "*************************************\n";
  cout << "*      Seminar 3.08. Task №03       *\n";
  cout << "*************************************\n\n";

  string str = "";
  cout << "Enter sting\n";
  getline(cin, str);

  int len = str.length();

  int k=0;

  for (int i = 0; i < len; i++)
    if (!isdigit(str[i]))
      str[k++] = str[i];
  
  str.resize(k);

  if (len == 0)
    cout << "\nEmpty string\n";
  else if (len == k)
    cout << "\nString not changed\n";
  else 
    cout << "Changed string: " << str << " len = " << k << "\n";
  
  return 0;
}
