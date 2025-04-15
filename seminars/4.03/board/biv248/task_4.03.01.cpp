#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <iomanip>
using namespace std;

struct student {
  struct {
    string sn, fn, pn;
  } fio;
  struct {
    int year, month, day;
  } data;
};

int read_int(int low, int hi, string name) {
  int numb;
  do {
    cout << "Input " << name << " from " 
         << low << " to " << hi << endl;
    cin >> numb;
    if (cin.fail()) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      numb = -1;
    }
  } while (numb == -1 || numb < low || numb > hi);
  return numb;
}

string read_str(string name) {
  string s = "";
  do {
    cout << "Input " << name << endl;
    getline(cin, s);
  } while (s == "");
  return s;
}

void make_file(string filename) {
  ofstream f;
  f.open(filename);
  student buffer;
  string buf = "y";
  while (buf[0] == 'Y' || buf[0] == 'y'){
    buffer.fio.sn = read_str("surname");
    f << buffer.fio.sn << "\n";
    buffer.fio.fn = read_str("name");
    f << buffer.fio.fn << "\n";
    buffer.fio.pn = read_str("patronomyc");
    f << buffer.fio.pn << "\n";

    buffer.data.year = read_int(1900, 2025, "year");
    f << buffer.data.year << " ";
    buffer.data.month = read_int(1, 12, "month");
    f << buffer.data.month << " ";
    buffer.data.day = read_int(1, 31, "day");
    f << buffer.data.day << "\n\n";

    cout << "Continue Y/N";
    cin >> buf;
  }
  f.close();
}

void out_file(string filename) {
  fstream f;
  f.open(filename);
  if (!f){
    cout << "File error";
    return;
  }
  student buffer;
  string buf;
  while (!f.eof()){
    getline(f, buffer.fio.sn);
    if (buffer.fio.sn != "") {
      getline(f, buffer.fio.fn);
      getline(f, buffer.fio.pn);

      f >> buffer.data.year;
      f >> buffer.data.month;
      f >> buffer.data.day;

      getline(f, buf);
      getline(f, buf);

      cout << "Фамилия - " << buffer.fio.sn << "\n";
      cout << "Имя - " << buffer.fio.fn << "\n";
      cout << "Отчество - " << buffer.fio.pn << "\n";

      cout << "Дата рождения - " << buffer.data.day << "." << buffer.data.month << "." << buffer.data.year << "\n\n";
    }
  }
  f.close();  
}

int main() {
  cout << "*************************************\n";
  cout << "*      Seminar 4.03. Task №01       *\n";
  cout << "*************************************\n\n";

  string filename;
  cout << "Enter file name: ";
  getline(cin, filename);
  make_file(filename);
  out_file(filename);
  return 0;
}
