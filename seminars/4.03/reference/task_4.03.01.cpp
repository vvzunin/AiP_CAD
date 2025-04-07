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
  } dat;
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
  string ans;
  student st = {{"", "", ""}, {0, 0, 0}};
  ofstream f;
  f.open(filename);
  if (!f)
    cout << "File not found!\n";
  else {
    cout << "Input data for file:\n";
    do {
      st.fio.sn = read_str("Surname");
      f << st.fio.sn << endl;
      st.fio.fn = read_str("Name");
      f << st.fio.fn << endl;
      st.fio.pn = read_str("Patronumic");
      f << st.fio.pn << endl;
      st.dat.day = read_int(1, 31, "Day");
      st.dat.month = read_int(1, 12, "Month");
      st.dat.year = read_int(1900, 2025, "Year");
      f << st.dat.day << "  " << st.dat.month << "  " << st.dat.year << endl;
      cout << "Continue?(y/n)" << endl;
      cin >> ans;
    } while (ans[0] == 'y' || ans[0] == 'Y');
    f.close();
    cout << "File is ready!" << endl;
  }
}

void out_file(string filename) {
  student st;
  string s;
  fstream F;
  F.open(filename);
  if (!F)
    cout << "File not found!\n";
  else {
    cout << "Data in file:\n";
    while (!F.eof()) {
      if (getline(F, st.fio.sn)) {
        cout << "Surname: " << st.fio.sn << endl;
        getline(F, st.fio.fn);
        cout << "Name: " << st.fio.fn << endl;
        getline(F, st.fio.pn);

        cout << "Patronumic: " << st.fio.pn << endl;
        F >> st.dat.day >> st.dat.month >> st.dat.year;
        getline(F, s);
        cout << "Date: " << setfill('0') << setw(2) << st.dat.day << "."
             << setfill('0') << setw(2)<< st.dat.month << "."
             << st.dat.year << endl;
        cout << "Press any key..." << endl;
        getline(cin, s);
      }
    }
    F.close();
    cout << "That is all!\n";
  }
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
