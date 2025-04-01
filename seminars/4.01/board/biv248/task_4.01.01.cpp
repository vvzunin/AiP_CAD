#include <iostream>
using namespace std;
#include <cctype>
#include <string>

int substr(int k1, string mas1[], string mas2[], int nom[]) {
  int kol = 0;
  for (int i = 0; i<k1; i++){
    int len = mas1[i].length();
    int j = 0;
    while (j<len-2){
      if (mas1[i][j] == '/' && mas1[i][j+1] == '*'){
        int k = j+2;
        int k1 = -1;
        for (j = k; j<len-1&&k1==-1; j++) {
          if (mas1[i][j+1] == '/' && mas1[i][j] == '*') {
            k1 = j-1;
          }
        }
        if (k1>=k) {
          mas2[kol].assign(mas1[i], k, (k1-k+1));
          nom[kol] = i;
          kol+=1;
        }
      }
      j++;
    }
  } 
  return kol;
}

int nompodstr(int k2, string mas2[]) {
  int maks = -1;
  int maks_num = 0;
  int j = 0;
  for (int i = 0; i<mas2->length(); i++){
    for (j = 0; j<mas2[i].length()&&isdigit(mas2[i][j]);j++);
    if (j>maks_num){
      maks_num = j;
      maks = i;
    }
  }
  return maks;
}

bool change(string &s) {
  bool f = false;
  for (int i = 0; i<s.length(); i++){
    if (s[i] >='A'&& s[i]<='J'){
      s[i] = s[i] - 'A' + '0';
      f = true;
    }
  }
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
      cout << "No necessary substrings!\n";
    else {
      cout << "Necessary substring: " << mas2[num] << "\n";
      if (change(mas1[nom[num]]))
        cout << "Changed string: " << mas1[nom[num]] << endl;
      else
        cout << "No changes in string!\n";
    }
  }
  return 0;
}