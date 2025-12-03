#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, caseNum = 1;

  while (cin >> n) {
    vector<int> b(n);
    bool bad = false;

    for (int i = 0; i < n; i++) {
      cin >> b[i];
      if (i > 0 && b[i] <= b[i - 1]) {
        bad = true; // not strictly increasing
      }
    }

    // If still okay, check pair sums
    vector<bool> used(20001, false);

    if (!bad) {
      for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
          int sum = b[i] + b[j];
          if (used[sum]) {
            bad = true;
            break;
          }
          used[sum] = true;
        }
        if (bad)
          break;
      }
    }

    cout << "Case #" << caseNum++ << ": ";
    if (!bad)
      cout << "It is a B2-Sequence.\n\n";
    else
      cout << "It is not a B2-Sequence.\n\n";
  }
}
