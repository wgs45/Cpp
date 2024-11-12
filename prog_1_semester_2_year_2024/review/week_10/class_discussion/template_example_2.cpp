#include <iostream>
#include <math.h>
using namespace std;

template <typename T> T add(T a, T b) { return (a + b) * 2; }

int add(double a, double b) { return round(a + b); }

string add(string a, string b) { return a + b; }

int main() {
  cout << add(3.5, 6.2) << endl;
  cout << add(4, 3) << endl;
  cout << add((string) "Hello", (string) "There!") << endl;

  return 0;
}
