#include <iostream>
using namespace std;

class Person {
public:
  int ID;

  // Constructor to initialize id with the specified value
  Person(int id) { ID = id; }

  Person() {} // Default constructor
};

// Template class to create an array of any type and size
template <class T, int size> class Array {
public:
  // Array to store elements of type T with size 'size'
  T elements[size];

  // Overloaded operator[] for non-const access, allows modification
  T &operator[](int index) { return elements[index]; }

  // Ocerloaded operator[] for const access, ensures read-only access
  const T &operator[](int index) const { return elements[index]; }
};

int main() {
  Person p1(160);
  Person p2(170);

  Array<Person, 5> a;
  a[0] = p1;
  cout << a[0].ID << endl;
  a[1] = p2;
  cout << a[1].ID << endl;

  return 0;
}
