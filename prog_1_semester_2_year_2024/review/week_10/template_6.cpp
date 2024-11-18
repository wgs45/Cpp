#include <iostream>
using namespace std;

// class A with 2 unknown data types T, and S
template <typename T, typename S> class A {
public:
  T x; // member variable 1
  S y; // member variable 2

  A(T);        // Constructor with one parameter
  void show(); // Member function
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
  A<double, int> a(5.6); // Cast T using "double", S using "int"
  a.show();              // Call the member function

  return 0;
}
