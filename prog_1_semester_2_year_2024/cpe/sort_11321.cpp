// 11321 - Sort! Sort!! and Sort!!!
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int M; // Global variable

bool custom_compare(int a, int b) {
  int modA = a % M;
  int modB = b % M;

  if (modA != modB)
    return modA < modB; // Rule 1: Sort by modulo M

  bool oddA = a % 2 != 0;
  bool oddB = b % 2 != 0;

  // Rule 2: Odd before even
  if (oddA && !oddB)
    return true;
  if (!oddA && oddB)
    return false;

  // Rule 3:
  if (oddA && oddB)
    return a > b; // Among odds, bigger comes first
  if (!oddA && !oddB)
    return a < b; // Among evens, smaller comes first

  return false;
}

int main() {
  int N;

  while (cin >> N >> M) {
    cout << N << " " << M << endl;

    if (N == 0 && M == 0)
      break;

    vector<int> numbers(N); // Resizable array
    for (int i = 0; i < N; ++i) {
      cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end(), custom_compare);

    for (int num : numbers) {
      cout << num << endl;
    }
  }

  return 0;
}
