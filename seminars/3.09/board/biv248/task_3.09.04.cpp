#include <iostream>
#include <cctype>
#include <string>
using namespace std;

bool change(string &s) {
  bool flag = false;
  
  for (int i = 0; i < s.length(); i++){
    if (s[i] == '['){
      int j;
      for (j = i + 1; j < s.length() && isalpha(s[j]); j++);
      if (s[j] == ']' && j != s.length() && j != i + 1){
        s.resize(s.length() + j - i - 1);
        for (int l = s.length() - (j - i - 1); l >= j ; l--)
          s[l + j - i - 1] = s[l];
        for (int l = i + 1; l < j + j - i - 1; l++)
          s[l] = '.';
        flag = true;
        i = j + j - i - 1;
      }
    }
  }
  return flag;
}

int main() {
  cout << "*************************************\n";
  cout << "*      Seminar 3.09. Task №04       *\n";
  cout << "*************************************\n\n";

  string s;
  cout << "Enter string:";
  getline(cin, s);

  if (change(s))
    cout << "New string:  " << s << endl;
  else
    cout << "No changes in the string!\n";

  return 0;
}