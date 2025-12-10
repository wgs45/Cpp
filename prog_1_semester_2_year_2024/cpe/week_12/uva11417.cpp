#include <iostream>
using namespace std;

int gcd(int a, int b) {
  while (b != 0) {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int main() {
  int N;
  while (cin >> N && N != 0) {
    int sum = 0;
    for (int i = 1; i < N; i++) {
      for (int j = i + 1; j <= N; j++) {
        sum += gcd(i, j);
      }
    }
    cout << sum << "\n";
  }
  return 0;
}
