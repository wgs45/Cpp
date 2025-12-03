#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  while (n--) {
    int s, d;
    cin >> s >> d;

    // Rule 1: sum cannot be smaller than difference
    // Rule 2: (s + d) must be even
    if (s < d || (s + d) % 2 != 0) {
      cout << "impossible\n";
    } else {
      int a = (s + d) / 2; // bigger score
      int b = (s - d) / 2; // smaller score
      cout << a << " " << b << "\n";
    }
  }
}
