#include <iostream>
using namespace std;
#include <cctype>
#include <string>

int substr(int k1, string mas1[], string mas2[], int nom[]) {
  int n, i, j, j1, j2;
  int k2 = 0;
  for (i = 0; i < k1; ++i)   {
    j = 0;
    n = mas1[i].length();
    j1 = -1;
    j2 = -1;
    while (j < n - 1)
      if (mas1[i][j] == '/' && mas1[i][j + 1] == '*') {
        j1 = j + 2;
        j = j + 2;
        while (j < n - 1 && j2 == -1)
          if (mas1[i][j] == '*' && mas1[i][j + 1] == '/')
            j2 = j - 1;
          else
            j = j + 1;
        if (j1 != -1 && j2 != -1 && j1 <= j2) {
          mas2[k2].assign(mas1[i], j1, j2 - j1 + 1);
          nom[k2++] = i;
        }
        j1 = -1;
        j2 = -1;
      }
      else
        j = j + 1;
  }
  return k2;
}
int nompodstr(int k2, string mas2[]) {
  int i, j, max, maxi;
  max = 0;
  maxi = -1;
  for (i = 0; i < k2; ++i) {
    j = 0;
    while (j < mas2[i].length() && isdigit(mas2[i][j]))
      ++j;
    if (j > max) {
      max = j;
      maxi = i;
    }
  }
  return maxi;
}

bool change(string &s) {
  bool f = false;
  int i;
  for (i = 0; i < s.length(); ++i)
    if (s[i] >= 'A' && s[i] <= 'J') {
      f = true;
      s[i] = s[i] - 'A' + '0';
    };
  return f;
}

int main() {
  int num, i, k1, k2;
  string s;
  do {
    cout << "Enter number of lines: ";
    cin >> k1;
    if (cin.fail())
      cin.clear();
    getline(cin, s);
  } while (k1 <= 0);

  int nom[5 * k1];
  string mas1[k1], mas2[5 * k1];
  
  cout << "Enter " << k1 << " strings:" << endl;
  for (i = 0; i < k1; ++i)
    getline(cin, mas1[i]);
  cout << endl;

  k2 = substr(k1, mas1, mas2, nom);

  if (k2 == 0)
    cout << "No substrings!" << endl;
  else {
    cout << "Substrings:" << endl;
    for (i = 0; i < k2; ++i)
      cout << mas2[i] << endl;
    cout << endl;

    num = nompodstr(k2, mas2);

    if (num == -1)
      cout << "No necessary substrings!" << endl;
    else {
      cout << "Necessary substring: " << mas2[num] << "\n";
      if (change(mas1[nom[num]]))
        cout << "Changed string: " << mas1[nom[num]] << endl;
      else
        cout << "No changes in string!\n" << endl;
    }
  }
  return 0;
}
