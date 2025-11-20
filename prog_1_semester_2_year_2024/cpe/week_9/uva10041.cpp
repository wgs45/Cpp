#include <iostream>
#include <math.h>
using namespace std;

int main() {
  int r, a[500], t, j, temp, median;
  int sum;

  cin >> r;

  while (r--) {
    int i = 0;

    cin >> t;

    for (i = 0; i < t; i++) {
      cin >> a[i];
    }

    for (i = 0; i < t; i++)
      for (j = 0; j < t - i - 1; j++)
        if (a[j] > a[j + 1]) {
          temp = a[j];
          a[j] = a[j + 1];
          a[j + 1] = temp;
        }
    sum = 0;
    median = a[t / 2];

    for (i = 0; i < t; i++)
      sum += abs(a[i] - median);
    cout << sum << endl;
  }

  return 0;
}
