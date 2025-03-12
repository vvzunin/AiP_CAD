#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
using namespace std;

int main() {
  cout << "*************************************\n";
  cout << "*      Seminar 3.09. Task №02       *\n";
  cout << "*************************************\n\n";

  int i, j, l, c;
  bool flag;
  cout << "Enter one string: ";
  string s = "";
  getline(cin, s);
  
  cout << "Original string:  " << s << '\n';
  l = s.length();
  flag = false;
  
  for (i = 0; i < l - 1; i++)
    if (isupper(s[i]) && isalpha(s[i]))
      for (j = i + 1; j < l; j++)
        if (isupper(s[j]) && isalpha(s[j]) && s[i] > s[j]) {
          flag = true;
          c = s[i];
          s[i] = s[j];
          s[j] = c;
        }
  
  if (!flag) 
    cout << "No sorting!\n";
  else 
    cout << "Sorted string:    " << s << '\n';
  
  return 0;
}
