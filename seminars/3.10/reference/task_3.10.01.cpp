#include <iostream>
#include <cctype>
#include <string>
using namespace std;

bool change(string &s) {
  int l = s.length();
  bool flag = false;
  int i = 0;
  
  while (i < l)
    if (s[i] == '{') {
      int t = i + 1, j;
      for (j = i + 1; j < l && isdigit(s[j]); j++);
      
      if (s[j] == '}' && j - t != 0 && j != l) {
        flag = true;
        int z = s[j - 1] - '0';
        int p = j - t; int k;
        
        for (k = j; k < l; k++)
          s[k - p] = s[k];
        
        s.resize(l + z - p);
        
        for (k--; k >= t; k--)
          s[k + z] = s[k];
        
        for (i = t; i < t + z; i++)
          s[i] = '*';
        
        l += z - p;
      }
      else
        i++;
    }
    else
      i++;  
  return flag;
}

int main() {
  cout << "*************************************\n";
  cout << "*      Seminar 3.10. Task №01       *\n";
  cout << "*************************************\n\n";

  string s;
  cout << "Enter string: ";
  getline(cin, s);
  
  if (change(s))
    cout << "New string:   " << s << endl;
  else
    cout << "No changes in string!\n";
  
  return 0;
}
