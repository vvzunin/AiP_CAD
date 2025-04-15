#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
using namespace std;

struct student {
  struct {
    string sn, fn, pn;
  } fio;
  struct {
    int year, month, day;
  } dat;
};

int make_array(string filename, string longest[]) {
  int max = 0;
  int num = 0;
  student st = {{"", "", ""}, {0, 0, 0}};
  string s;
  fstream F;
  F.open(filename);
  if (!F)
    cout << "File not found!\n";
  else   {
    cout << "Data in file:\n";
    string fam[100];
    int kfam = 0, maxlen = 0;
    while (!F.eof()) {
      if (getline(F, st.fio.sn)) {
        cout << "Surname: " << st.fio.sn << endl;
        // TODO
        // fam[kfam++] = st.fio.sn;
        // if (st.fio.sn.length() > maxlen){
        //   maxlen = st.fio.sn.length();
        // }

        if (st.fio.sn.length() > maxlen){
          kfam = 0;
          longest[kfam++] = st.fio.sn;

          maxlen = st.fio.sn.length();
        }
        else if (st.fio.sn.length() == maxlen){
          longest[kfam++] = st.fio.sn;
        }

        getline(F, st.fio.fn);
        cout << "Name: " << st.fio.fn << endl;
        getline(F, st.fio.pn);
        cout << "Patronumic: " << st.fio.pn << endl;
        F >> st.dat.day >> st.dat.month >> st.dat.year;
        cout << "Date: " << setfill('0') << setw(2) << st.dat.day << "."
             << setfill('0') << setw(2) << st.dat.month << "."
             << st.dat.year << endl;
        getline(F, s);
      }
    }
    return kfam;
  }
}

int main() {
  cout << "*************************************\n";
  cout << "*      Seminar 4.03. Task №02       *\n";
  cout << "*************************************\n\n";

  string filename, longest[100];
  cout << "Enter file name" << endl;
  cin >> filename;
  int k = make_array(filename, longest);
  if (!k)
    cout << "Surname not found!\n";
  else   {
    cout << "Enter file name for result: ";
    cin >> filename;
    fstream F;
    F.open(filename);
    cout << "Longest surnames:\n";
    for (int i = 0; i < k; i++) {
      cout << "\t" << longest[i] << endl;
      F << longest[i] << endl;
    }
    F.close();
  }
  return 0;
}