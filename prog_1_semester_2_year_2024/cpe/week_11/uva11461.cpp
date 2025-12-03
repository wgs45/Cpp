#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int a, b;
  while (cin >> a >> b && !(a == 0 && b == 0)) {

    int countB = floor(sqrt(b));
    int countA = floor(sqrt(a - 1));

    cout << countB - countA << "\n";
  }
}
