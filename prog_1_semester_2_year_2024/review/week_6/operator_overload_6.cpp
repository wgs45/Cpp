#include <iostream>
using namespace std;

class Date {
  int month, day, year;

public:
  friend istream &operator>>(istream &istream_1, Date &date_1);
  friend ostream &operator<<(ostream &ostream_1, const Date &date_1);
};

istream &operator>>(istream &istream_1, Date &date_1) {
  cout << "Please enter year: ";
  istream_1 >> date_1.year;
  cout << "Please enter month: ";
  istream_1 >> date_1.month;
  cout << "Please enter day: ";
  istream_1 >> date_1.day;
  return istream_1;
}

ostream &operator<<(ostream &ostream_1, const Date &date_1) {
  ostream_1 << "Date: " << date_1.day << "/" << date_1.month << "/"
            << date_1.year << endl;
  return ostream_1;
}

int main() {
  Date date_1;

  cin >> date_1;
  cout << date_1;

  return 0;
}
