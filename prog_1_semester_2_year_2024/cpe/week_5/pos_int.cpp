// uva 11332
#include <iostream>
using namespace std;

int main() {
  int n;
  long long int t;

  while (cin >> n) {
    if (n == 0)
      break;

    t = 0;
    while (1) {
      while (n != 0) {
        t = t + (n % 10);
        n = n / 10;
      }

      if (t / 10 == 0)
        break;
      else {
        n = t;
        t = 0;
      }
    }
    cout << t << endl;
  }

  return 0;
}
