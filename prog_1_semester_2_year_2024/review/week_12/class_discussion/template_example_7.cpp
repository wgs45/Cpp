#include <iostream>
using namespace std;

// Class A with 2 unknown data types T, and S
template <typename T, typename S = int> class A {
public:
  T x; // Member variable 1
  S y; // Member variable 2, and its data type can be different from variable 1

  A(T);        // Parameterized constructor (1 parameter)
  void show(); // Mmeber function
};

// The body of the constructor
template <typename T, typename S> A<T, S>::A(T _x) {
  this->x = _x;
  this->y = 6;
}

// The body of the member function
template <typename T, typename S> void A<T, S>::show() {
  cout << x << ", " << y << endl;
}

int main() {
  A<double> a(5.6); // Cast T using "double", S using "int"
  a.show();

  return 0;
}
