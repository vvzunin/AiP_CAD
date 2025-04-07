#include <fstream> //для работы с файлом
#include <iostream>
#include <string>
using namespace std;

int main() {
  cout << "*************************************\n";
  cout << "*      Seminar 4.02. Task №01       *\n";
  cout << "*************************************\n\n";

  string filename; // запрашиваем имя файла
  cout << "Input file name: ";
  getline(cin, filename);

  int n;
  double a;
  // открываем файл для записи
  ofstream f;
  f.open(filename); // даем ему имя
  cout << "Input numbers, end of input is letter :\n";
  do { // читаем числа по одному и записываем в файл
    cout << "a = ";
    cin >> a;
    if (!cin.fail())
      f << "  " << a; // записываем число в файл, разделитель - пробел
  } while (!cin.fail());
  cin.clear();
  f.close(); // закрываем файл

  fstream F;        // открываем файл для чтения
  F.open(filename); // даём ему имя
  if (!F)           // проверяем что он открыт
    cout << "File not found!\n";
  else {
    n = 0;
    while (!F.eof()) {
      F >> a;
      if (a > 0)
        n++;
    }
    F.close();
    if (n)
      cout << "\nn = " << n << endl;
    else
      cout << "No positive numbers in file!\n";
  }

  return 0;
}