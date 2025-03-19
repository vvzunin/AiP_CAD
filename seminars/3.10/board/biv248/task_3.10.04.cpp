#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int newArray(int n, string s[], string s1[]) {
  int n_subs = 0;
  int i, j, t, size_sub, position_sub;
  for (i = 0; i < n; i++) {
    size_sub = -1;
    position_sub = -1;
    for (j = 0; j < s[i].length(); j++) {
      if (isdigit(s[i][j])) {
        t = j;
        for (j = j + 1; j < s[i].length() && isdigit(s[i][j]); j++);
        if (size_sub < j - t) {
          size_sub = j - t;
          position_sub = t;
        }
      }
    }
    if (position_sub != -1)
      s1[n_subs++].assign(s[i], position_sub, size_sub);
  }
  return n_subs;
}

int main() {
  cout << "*************************************\n";
  cout << "*      Seminar 3.10. Task №04       *\n";
  cout << "*************************************\n\n";

  int n;
  cout << "Enter n = ";
  cin >> n;
  string t;
  getline(cin, t);
  string s[n], s1[n];
  
  cout << "Enter strings:" << endl;
  for (int i = 0; i < n; i++)
    getline(cin, s[i]);
  
  int n1 = newArray(n, s, s1);
  if (!n1)
    cout << "Array is empty!\n";
  else {
    cout << "New array:\n";
    for (int i = 0; i < n1; i++)
      cout << s1[i] << endl;
  }
  
  return 0;
}
