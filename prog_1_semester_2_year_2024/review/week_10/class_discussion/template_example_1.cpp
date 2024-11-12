#include <iostream>
#include <math.h>
using namespace std;

// Template class to handle any datatype T
template <typename T> class MyClass {
public:
  T x; // Data member to store datatype of T

  // constructor
  MyClass(T _x) {
    this->x = _x; // Assign parameter to the member variable x
    cout << "This is a number!" << endl;
  }
};

// Template class to handle char datatype
template <> class MyClass<char> {
public:
  char x; // Dara member to store char datatype x

  // constructor
  MyClass(char _x) {
    this->x = _x; // Assign parameter to the member variable x
    cout << "This is a character!" << endl;
  }
};

int main() {
  MyClass<int> a(3);     // Create instance of MyClass with int datatype
  MyClass<float> b(5.2); // Create instance of MyClass with float datatype
  MyClass<char> c('x');  // Create instance of MyClass with char datatype

  return 0;
}
