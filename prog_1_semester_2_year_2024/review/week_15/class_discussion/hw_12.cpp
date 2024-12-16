// // homework 12 default answer
#include <iostream>
using namespace std;

template <class T> class Calculator {
public:
  T add(T a, T b) { return a + b; }
  T multiply(T a, T b) { return a * b; }
};

template <> class Calculator<string> {
public:
  string add(string a, string b) { return a + b; }
  string multiply(string a, int b) {
    int i;
    string t = "";
    for (i = 0; i < 3; i++) {
      t = t + a;
    }
    return t;
  }
};

int main() {
  Calculator<int> c;
  Calculator<string> d;
  cout << d.add("Hello", "World") << endl;
  cout << d.multiply("Hello", 3) << endl;
  cout << c.add(3, 5) << endl;
  cout << c.multiply(3, 5) << endl;
  return 0;
}
