#include <iostream>
using namespace std;

// Template class to define a static-sized array for any type and size
template <class T, int size> class Array {
public:
  // Static array to store elements of type T
  T elements[size];

  // Overloaded operator[] for non-const access, allows modification of elements
  T &operator[](int index) { return elements[index]; }

  // Overloaded operator[] for const, ensures read-only access
  const T &operator[](int index) const { return elements[index]; }
};

int main() {
  Array<int, 5> a;
  a[0] = 20;
  a[1] = 30;
  cout << a[0] << " " << a[1];
  cout << endl;

  return 0;
}
