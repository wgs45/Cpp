#include <iostream>
using namespace std;

bool isPrime(int n) {
  if (n < 3)
    return false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0)
      return false;
  }
  return true;
}

int reverseNum(int n) {
  int r = 0;
  while (n > 0) {
    r = r * 10 + n % 10;
    n /= 10;
  }
  return r;
}

int main() {
  int n;

  while (cin >> n) {
    if (!isPrime(n)) {
      cout << n << " is not prime." << endl;
      continue;
    }

    int rev = reverseNum(n);

    if (rev != n && isPrime(rev)) {
      cout << n << " is emrip." << endl;
    } else {
      cout << n << " is prime." << endl;
    }
  }

  return 0;
}
