// uva 11150 onlineJudge
#include <iostream>
using namespace std;

int main() {
  long long int n = 0;

  while (cin >> n) {
    int sum = n;

    while (n >= 3) {
      sum += n / 3;
      n = n / 3 + n % 3;
      ;
    }
    if (n == 2)
      sum++;
    cout << sum << endl;
  }

  return 0;
}
