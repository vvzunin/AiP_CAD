#include <iostream>
#include <cctype>
#include <string>
using namespace std;

bool change(int n, string s[]) {
  string s1;
  int num[n], i, j, c;
  bool flag = false, f;
  
  for (i = 0; i < n; i++) {
    num[i] = 0;
    for (j = 0; j < s[i].length(); j++)
      if (isdigit(s[i][j])) num[i]++;
  }

  do {
    f = true;
    for (i = 0; i < n - 1; i++)
      if (num[i] > num[i + 1]) {
        f = false;
        flag = true;
        s1 = s[i];
        s[i] = s[i + 1];
        s[i + 1] = s1;
        c = num[i];
        num[i] = num[i + 1];
        num[i + 1] = c;
      }
  } while (!f);
  
  return flag;
}

int main() {
  cout << "*************************************\n";
  cout << "*      Seminar 3.10. Task №02       *\n";
  cout << "*************************************\n\n";

  int n;
  cout << "Enter n = ";
  cin >> n;
  string t;
  getline(cin, t); // Пропускаем конец строки
  string s[n];
  
  cout << "Enter strings:\n";
  for (int i = 0; i < n; i++)
    getline(cin, s[i]);
  
  bool f = change(n, s);
  if (f) {
    cout << "Changed strings:" << endl;
    for (int i = 0; i < n; i++)
      cout << s[i] << endl;
  } else {
    cout << "No changes in strings!" << endl;
  }
  
  return 0;
}