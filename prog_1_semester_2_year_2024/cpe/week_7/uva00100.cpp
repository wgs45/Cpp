// OnlineJudge uva 00100
#include <iostream>
using namespace std;

int main() {
  int i, j;
  while (cin >> i >> j) {
    int start = i, end = j;

    if (i == 0 && j == 0)
      break;

    if (i > j)
      swap(i, j);
    int max_cycle = 0;

    for (int n = i; n <= j; n++) {
      int count = 1;
      long value = n;
      while (value != 1) {
        if (value % 2 == 0)
          value /= 2;
        else
          value = value * 3 + 1;
        count++;
      }
      if (count > max_cycle)
        max_cycle = count;
    }

    cout << start << " " << end << " " << max_cycle << endl;
  }
  return 0;
}
