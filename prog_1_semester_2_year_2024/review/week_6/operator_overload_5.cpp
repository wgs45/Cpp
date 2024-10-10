#include <iostream>
using namespace std;

class Date {
  int month, day, year;

public:
  Date(int m, int d, int y) { month = m, day = d, year = y; }

  friend ostream &operator<<(ostream &os, const Date &dt);
};

ostream &operator<<(ostream &os, const Date &dt) {
  os << dt.month << "/" << dt.day << "/" << dt.year;
  return os;
}

int main() {
  Date dt(5, 6, 92);
  cout << "Date: " << dt << endl;

  return 0;
}
