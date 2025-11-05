#include <iomanip>
#include <iostream>
using namespace std;

void bangla(long long int n) {
  if (n >= 10000000) {
    bangla(n / 10000000);
    cout << " kuti";
    n %= 10000000;
  }

  if (n >= 100000) {
    bangla(n / 100000);
    cout << " lakh";
    n %= 100000;
  }

  if (n >= 1000) {
    bangla(n / 1000);
    cout << " hajar";
    n %= 1000;
  }

  if (n >= 100) {
    bangla(n / 100);
    cout << " shata";
    n %= 100;
  }

  if (n > 0)
    cout << " " << n;
}

int main() {
  long long int input;
  int count = 1;

  while (cin >> input) {
    cout << setw(4) << count++ << ".";
    if (input == 0) {
      cout << " 0" << endl;
      continue;
    }
    bangla(input);
    cout << endl;
  }

  return 0;
}
