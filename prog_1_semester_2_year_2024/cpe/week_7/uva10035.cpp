#include <iostream>
using namespace std;

int main() {
  unsigned long long a, b;

  while (1) {
    cin >> a >> b;

    // stop condition
    if (a == 0 && b == 0) {
      break;
    }

    int carry = 0, count = 0;

    while (a > 0 || b > 0) {
      int digitA = a % 10;
      int digitB = b % 10;

      if (digitA + digitB + carry >= 10) {
        carry = 1;
        count++;
      } else {
        carry = 0;
      }
      a /= 10;
      b /= 10;
    }

    if (count == 0) {
      cout << "No carry operation." << endl;
    } else if (count == 1) {
      cout << "1 carry operation." << endl;
    } else {
      cout << count << " carry operations." << endl;
    }
  }

  return 0;
}
