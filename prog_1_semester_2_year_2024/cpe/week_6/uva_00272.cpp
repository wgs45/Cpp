// onlinejudge uva 00272
#include <iostream>
using namespace std;

int main() {
  char c;
  bool open = true; // true = next " is opening, false = closing

  while (cin.get(c)) {
    if (c == '"') {
      if (open) {
        cout << "``";
        open = false; // next one will be closing
      } else {
        cout << "''";
        open = true; // next one will be opening
      }
    } else {
      cout << c;
    }
  }

  return 0;
}
