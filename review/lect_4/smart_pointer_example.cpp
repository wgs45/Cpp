// Smart pointer example in C++ (Source code from geeks for geeks)
#include <iostream>
using namespace std;

class Smart_pointer {
  int *ptr;

public:
  // Constructor
  // explicit keywords
  explicit Smart_pointer(int *p = NULL) { ptr = p; }

  // Destructor
  ~Smart_pointer() { delete (ptr); }

  // overloading deferencing operator
  int &operator*() { return *ptr; }
};

int main() {
  Smart_pointer ptr(new int());
  *ptr = 20;
  cout << *ptr << endl;

  // We don't need to call delete ptr: when the object
  // ptr goes out of scope, the destructor for it is
  // automatically called and destructor does delete ptr.

  return 0;
}
