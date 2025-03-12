#include <string>
#include <iostream>
#include <cctype>
using namespace std;

int main() {
  cout << "*************************************\n";
  cout << "*      Seminar 3.09. Task №03       *\n";
  cout << "*************************************\n\n";

  int i, j, z, n;
  bool flag;
  cout << "Enter one string: ";
  string s = "";
  getline(cin, s); // Ввод строки
  
  flag = false;
  i = 0;
  n = s.length();
  
  while (i < s.length())
    if (isdigit(s[i])) { // Цифра
      z = s[i] - '0'; // Разность кодов, равна цифре
      if (!(z % 2)) { // Четная цифра
        flag = true;
        s.resize(n + 2); // Устанавливается новая длина строки
        for (j = n - 1; j >= i; j--)
          s[j + 2] = s[j]; // Освобождение места для вставки
        s[i] = '0';
        s[i + 1] = '0'; // Вставка нулей
        
        i = i + 3; // Пропуск нулей и цифры
        n = n + 2; // Новая длина строки
      }
      else
        i++;
    }
    else
      i++;
  
  // Анализ существования результата
  if (!flag) 
    cout << "No changes in string!\n";
  else 
    cout << "Changed string: " << s << endl;
  
  return 0;
}
