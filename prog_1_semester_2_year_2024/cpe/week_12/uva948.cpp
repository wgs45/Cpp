#include <iostream>
#include <vector>
using namespace std;

int main() {
  // 1. Build Fibonacci numbers (F[0]=0, F[1]=1, start real from F[2])
  vector<int> fib(40);
  fib[0] = 0;
  fib[1] = 1;

  for (int i = 2; i < 40; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }

  int T;
  cin >> T;

  while (T--) {
    int n;
    cin >> n;

    cout << n << " = ";

    int num = n;
    bool started = false; // To control zeros aftere first 1

    // 2. Greedy from largest fibonacci number
    for (int i = 39; i >= 2; i--) {
      if (num >= fib[i]) {
        num -= fib[i];
        cout << "1";
        started = true;
      } else if (started) {
        cout << "0";
      }
    }
    cout << " (fib)" << endl;
  }

  return 0;
}
