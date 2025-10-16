// uva 10783 onlineJudge
#include <iostream>
using namespace std;

int main() {
  int t;

  cin >> t;

  for (int case_num = 1; case_num <= t; case_num++) {
    int a, b;

    cin >> a;
    cin >> b;

    int sum = 0;
    for (int i = a; i <= b; i++) {
      if (i % 2 != 0) {
        sum += i;
      }
    }

    cout << "Case " << case_num << ": " << sum << endl;
  }

  return 0;
}
