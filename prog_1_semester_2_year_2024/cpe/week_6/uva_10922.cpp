// onlinejudge uva 10922
#include <iostream>
#include <string>
using namespace std;

int main() {
  string n;

  while (cin >> n && n != "0") {
    int count = 0;
    string s = n;

    while (true) {
      int ans = 0;

      for (int i = 0; i < n.length(); i++) {
        ans += n[i] - '0';
      }
      if (ans % 9 == 0) {
        count++;
      }
      n = to_string(ans);

      if (n.length() == 1) {
        break;
      }
    }

    if (count == 0) {
      cout << s << " is not a multiple of 9" << endl;
    } else {
      cout << s << " is a multiple of 9 and has 9-degree " << count << endl;
    }
  }

  return 0;
}
