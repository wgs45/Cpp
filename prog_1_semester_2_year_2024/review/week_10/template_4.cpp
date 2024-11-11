#include <iostream>
using namespace std;

template <typename T> class A {
public:
  T x;
  A(T _x) { this->x = _x; }

  void show() { cout << x << endl; }
};

int main() {
  A<int> a(5);
  a.show();

  return 0;
}
