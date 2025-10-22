// Rare Easy Problem (uva 10633)
#include <iostream>
using namespace std;

int main() {
  long long int x, m;

  while (1) {
    cin >> x;
    if (x == 0)
      break;

    for (int i = 9; i >= 0; i--) { // x = 18
      // m = (x - a) / 9
      if ((x - i) % 9 == 0) {  // 18 - 9 % 9
        m = (x - i) / 9;       // m = 1
        cout << x + m << endl; // 18 + 1
      }
    }
    cout << endl;
  }

  return 0;
}
