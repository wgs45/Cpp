// onlinejudge uva 10292
#include <iostream>
#include <string.h>
using namespace std;

int main() {
  char n[1001] = {0};

  while (cin >> n) {
    if (n[0] == '0' && strlen(n) == 1) {
      break;
    } else {
      int i, sum = 0;

      for (i = 0; i < strlen(n); i++) {
        if (i % 2 == 0) {
          sum += (n[i] - '0');
        } else {
          sum -= (n[i] - '0');
        }
      }
      if (sum % 11 == 0) {
        cout << n << " is a multiple of 11." << endl;
      } else {
        cout << n << " is not a multiple of 11." << endl;
      }
    }
  }

  return 0;
}
