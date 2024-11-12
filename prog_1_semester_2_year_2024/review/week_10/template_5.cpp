#include <iostream>
using namespace std;

template <typename T> // CLass A with one unknown data type T
class A {
public:
  T x;  // Member variables
  A(T); // Constructor with a single parameter

  void show(); // Member function
};

template <typename T> // The body of the constructor
A<T>::A(T _x) {
  this->x = _x;
}

template <typename T> // The body of the member function
void A<T>::show() {
  cout << x << endl;
}

int main() {
  A<int> a(5); // Typecasting T using "int"
  a.show();

  return 0;
}
