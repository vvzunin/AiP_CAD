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
  bool flag = false;
  cout << "Enter one string: ";
  string s = "";
  getline(cin, s);
  
  cout << "Original string:  " << s << '\n';  
  
  // Код здесь
  for (int i = 0; i < s.length() - 1; i++)
    if (isalpha(s[i]) && isupper(s[i]))
      for (int j = i + 1; j < s.length(); j++)
        if (isalpha(s[j]) && isupper(s[j]) && (s[i] > s[j])){
          c = s[i];
          s[i] = s[j];
          s[j] = c;
          flag = true;
        }
  
  if (!flag) 
    cout << "No sorting!\n";
  else 
    cout << "Sorted string:    " << s << '\n';
  
  return 0;
}
