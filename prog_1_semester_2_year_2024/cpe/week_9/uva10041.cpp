#include <iostream>
#include <math.h>
using namespace std;

int main() {
  int caseNum, r[500], streetNum, temp, median, sum;

  cin >> caseNum;

  while (caseNum--) {
    int i = 0, j = 0;

    cin >> streetNum;

    for (i = 0; i < streetNum; i++) {
      cin >> r[i];
    }

    for (i = 0; i < streetNum; i++) {
      for (j = 0; j < streetNum - i - 1; j++) {
        if (r[j] > r[j + 1]) {
          temp = r[j];
          r[j] = r[j + 1];
          r[j + 1] = temp;
        }
      }
    }
    sum = 0;
    median = r[streetNum / 2];

    for (i = 0; i < streetNum; i++) {
      sum += abs(r[i] - median);
    }
    cout << sum << endl;
  }

  return 0;
}
