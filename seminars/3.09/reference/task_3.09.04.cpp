#include <iostream>
#include <cctype>
#include <string>
using namespace std;

bool change(string &s) {
  int l = s.length();
  bool flag = false;
  int i = 0;

  while (i < l)
    if (s[i] == '[') {
      int t = i, j;
      for (j = i + 1; j < l && isalpha(s[j]); j++);

      if (s[j] == ']' && j - t != 1 && j != l) {
        flag = true;
        int n = j - t - 1;
        s.resize(l + n);

        int k;
        for (k = l - 1; k > t; k--)
          s[k + n] = s[k];

        for (k = t + 1; k < t + 1 + 2 * n; k++)
          s[k] = '.';

        i = k + 1;
        l += n;
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
  cout << "*      Seminar 3.09. Task №04       *\n";
  cout << "*************************************\n\n";

  string s;
  cout << "Enter string:";
  getline(cin, s);

  if (change(s))
    cout << "New string: " << s << endl;
  else
    cout << "No changes in the string!\n";

  return 0;
}