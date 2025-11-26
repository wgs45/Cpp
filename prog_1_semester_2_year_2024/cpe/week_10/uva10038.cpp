#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int n;

  while (cin >> n) {
    int arr[3001];
    int mark[3001] = {0};

    // Read sequence
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    // Mark differences
    for (int i = 0; i < n - 1; i++) {
      int diff = abs(arr[i] - arr[i + 1]);
      if (diff > 0 && diff < n) {
        mark[diff] = 1;
      }
    }

    // Count how many valid differences
    int count = 0;
    for (int i = 1; i <= n - 1; i++) {
      if (mark[i] == 1)
        count++;
    }

    if (count == n - 1)
      cout << "Jolly\n";
    else
      cout << "Not jolly\n";
  }

  return 0;
}
