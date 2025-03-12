#include <iostream>
#include <string>
using namespace std;

int change(int n, string s[]) {
  int i, j, k = 0;
  
  for (i = 0; i < n; i++) {
    for (j = 0; j < s[i].length() && s[i][j] != '0'; j++);
    if (j < s[i].length())
      s[k++] = s[i];
  }
  return k;
}

int main() {
  cout << "*************************************\n";
  cout << "*      Seminar 3.10. Task №03       *\n";
  cout << "*************************************\n\n";
  
  int n;
  cout << "Enter n = ";
  cin >> n;
  string t;
  getline(cin, t);
  string s[n];
  
  cout << "Enter strings:\n";
  for (int i = 0; i < n; i++)
    getline(cin, s[i]);
  
  int n1 = change(n, s);
  if (!n1)
    cout << "Array is empty!" << endl;
  else if (n == n1)
    cout << "No changes in array!" << endl;
  else {
    cout << "Changed array:" << endl;
    for (int i = 0; i < n1; i++)
      cout << s[i] << endl;
  }
  
  return 0;
}
