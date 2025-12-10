#include <iostream>
using namespace std;

int main() {
  // Precomputed number of 1s for each hex digit 0–15
  int hexOnes[16] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};

  int T;
  cin >> T;

  while (T--) {
    int n;
    cin >> n;

    int x = n;
    int b1 = 0;

    // Count ones in full binary of n
    while (x > 0) {
      b1 += x % 2;
      x /= 2;
    }

    int y = n;
    int b2 = 0;

    // Count ones in each digit treated as hex
    while (y > 0) {
      int digit = y % 10;
      b2 += hexOnes[digit];
      y /= 10;
    }
    cout << b1 << " " << b2 << endl;
  }

  return 0;
}
