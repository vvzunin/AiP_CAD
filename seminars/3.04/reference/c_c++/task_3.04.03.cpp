#include <iostream>
using namespace std;

// Прототип функции
int *vstavka(int a[], int *na, int b[], int nb);

int main() {
  cout << "*************************************\n";
  cout << "*      Seminar 3.04. Task №03       *\n";
  cout << "*************************************\n\n";

  int a[30], b[10], na, nb, *up;

  // Ввод длины массива A с проверкой
  cout << "Введите длину массива A: na = ";
  cin >> na;
  cout << "Введите " << na << " элементов массива A:\n";
  for (up = a; up < a + na; up++)
    cin >> *up;

  // Ввод длины массива B с проверкой
  cout << "Введите длину массива B: nb = ";
  cin >> nb;
  cout << "Введите " << nb << " элементов массива B:\n";
  for (up = b; up < b + nb; up++)
    cin >> *up;

  // Вставка и вывод результата
  if (vstavka(a, &na, b, nb) == NULL)
    cout << "Вставки нет (в A нет четных элементов).\n";
  else {
    cout << "Массив A после вставки:\n";
    for (up = a; up < a + na; up++)
      cout << *up << "  ";
    cout << endl;
  }
  return 0;
}

// Функция возвращает адрес первого четного элемента в массиве a
int *vstavka(int a[], int *na, int b[], int nb) {
  int *u1, *ua, *ub;
  for (ua = a, u1 = NULL; ua < a + *na && u1 == NULL; ua++)
    if (*ua % 2 == 0)
      u1 = ua;

  if (u1) {
    for (ua = a + (*na) - 1; ua > u1; ua--)
      *(ua + nb) = *ua;
    for (ub = b; ub < b + nb; ub++)
      *(++ua) = *ub;
    *na += nb;
  }
  return u1;
}