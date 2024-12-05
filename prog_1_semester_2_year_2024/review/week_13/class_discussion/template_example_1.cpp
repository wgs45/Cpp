#include <iostream>
using namespace std;

// Template declaration for class "add", which takes two types: T and S
template <class T, class S> class add {
public:
  T x;         // Variable x of T types
  S y;         // Variable y of S types
  add(T, S);   // Constructor that accepts two paameters
  void show(); // Method to show the sum of x and y
};

template <class T, class S> add<T, S>::add(T _x, S _y) {
  this->x = _x;
  this->y = _y;
}

template <class T, class S> void add<T, S>::show() { cout << x + y << endl; }

int main() {
  add<double, int> a(3.5, 54);
  add<int, double> b(2, 6.8);
  add<int, int> c(5, 6);
  add<float, float> d(5.64, 6.12);

  a.show();
  b.show();
  c.show();
  d.show();

  return 0;
}
