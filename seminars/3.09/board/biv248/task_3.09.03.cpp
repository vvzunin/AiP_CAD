#include <string>
#include <iostream>
#include <cctype>
using namespace std;

int main() {
  cout << "*************************************\n";
  cout << "*      Seminar 3.09. Task №03       *\n";
  cout << "*************************************\n\n";

  int i, j, z, n;
  bool flag = false;
  cout << "Enter one string: ";
  string s = "";
  getline(cin, s); // Ввод строки
  
  // Код здесь
  for (int i = 0; i < s.length(); i++)
    if (isdigit(s[i]) && (s[i]- '0')%2 == 0) {
      flag = true;
      s.resize(s.length()+2);
      for (int j = s.length()-2; j >= i ; j--)
         s[j+2] = s[j];
      s[i]='0';
      s[i+1]='0';
      i += 2;
    }
  
  // Анализ существования результата
  if (!flag) 
    cout << "No changes in string!\n";
  else 
    cout << "Changed string: " << s << endl;
  
  return 0;
}
