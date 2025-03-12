#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int newArray(int n, string s[], string s1[]) {
  int i, j, j1, beg, max, n1 = 0;
  
  for (i = 0; i < n; i++) {
    j = 0;
    max = beg = -1;
    
    while (j < s[i].length())
      if (isdigit(s[i][j])) {
        j1 = j;
        while (j < s[i].length() && isdigit(s[i][j])) 
          j++;
        if (j - j1 > max) 
          max = j - j1, beg = j1;
      } else j++;
    
    if (beg != -1)
      s1[n1++].assign(s[i], beg, max);
    else
      cout << "In " << i << " no substrings" << endl;
  }
  return n1;
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
