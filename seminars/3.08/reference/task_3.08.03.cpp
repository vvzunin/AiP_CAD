#include <string>
#include <iostream>
#include <ctype.h>
using namespace std;

int main() {
  cout << "*************************************\n";
  cout << "*      Seminar 3.08. Task №03       *\n";
  cout << "*************************************\n\n";

  int i, k, l;
  string s = ""; 

  cout << "Enter one string: ";
  getline(cin, s);
  // Первые пробелы остаются в строке

  cout << "Original string: " << s << '\n'; 

  i = k = 0;
  l = s.length();
  cout << "Original length: " << l << '\n';

  for (; i < l; i++) {
    if (!isdigit(s[i])) 
      s[k++] = s[i];    
  }

  s.resize(k); 

  if (k == 0) 
    cout << "String is empty";
  else 
    if (l == k) 
      cout << "String was not changed";
    else 
      cout << "Changed string: " << s << '\n' 
           << "New length: " << s.length() << '\n'; 

  return 0;
}
