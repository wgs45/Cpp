#include <iostream>
using namespace std;

template <typename T> // Class A with one unknown data type T
class A {
public:
  T x;         // member variable
  A(T);        // Constructor with one parameter
  void show(); // member function
};

template <typename T> // The body of the Constructor
A<T>::A(T _x) {
  this->x = _x;
}

template <typename T> // The body of the member function
void A<T>::show() {
  cout << x << endl;
}

int main() {
  A<int> a(5);
  a.show();

  return 0;
}
