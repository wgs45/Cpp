#include <iostream>
using namespace std;

int main() {
  const int dayMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  const char *dayWeek[] = {"Friday",  "Saturday",  "Sunday",  "Monday",
                           "Tuesday", "Wednesday", "Thursday"};

  int T, month, day, i, totalDay;
  cin >> T;

  while (T--) {
    cin >> month >> day;
    totalDay = 0;

    for (i = 0; i < month; i++) {
      totalDay += dayMonth[i];
    }

    totalDay += day;
    cout << dayWeek[totalDay % 7] << endl;
  }
  return 0;
}
