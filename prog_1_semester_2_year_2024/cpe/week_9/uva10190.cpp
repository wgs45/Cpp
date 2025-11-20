#include <iostream>
using namespace std;

int main() {
  int m, n, i;

  while (cin >> n >> m) {
    if (m < 2 || n == 0 || n < m) {
      cout << "Boring!" << endl;
      continue;
    }

    int ans[100] = {n};

    for (i = 1;; i++) {
      if (ans[i - 1] == 1)
        break;

      if (ans[i - 1] % m) {
        i = -1;
        break;
      }

      ans[i] = ans[i - 1] / m;
    }

    if (i < 0)
      cout << "Boring!" << endl;
    else {
      cout << ans[0];
      for (n = 1; n < i; n++) {
        cout << " " << ans[n];
      }
      cout << endl;
    }
  }
  return 0;
}
