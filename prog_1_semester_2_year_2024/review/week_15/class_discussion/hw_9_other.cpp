// hw 9 alternative answer (using template and more complex approach)
#include <iostream>
using namespace std;

template <class T, class U> T add(T a, U b) { return a + b; }

float add(int a, float b) { return a + b; }

int main() {
  int a = 10, b = 5;
  float c = 3.5, d = 4.5;

  cout << add(a, b) << endl;
  cout << add(a, c) << endl;
  cout << add(c, a) << endl;
  cout << add(c, d) << endl;

  return 0;
}
