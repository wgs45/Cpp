#include <iostream>
using namespace std;

template <typename T> class MyClass {
public:
  T x;
  MyClass(T _x) { this->x = _x; }

  void show() { cout << this->x << endl; }
};

int main() {
  MyClass<int> a(3);
  MyClass<float> b(5.2);
  a.show();
  b.show();

  return 0;
}
