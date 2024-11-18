#include <iostream>
#include <typeinfo>
using namespace std;

template <typename T> class Box {
private:
  T width; // Private variable to store the width of the table

public:
  // Constructor
  Box(T w) : width(w) {}

  // Overload + operator to add two box objects of the same type
  Box operator+(const Box &other) const {
    if (typeid(this->width) != typeid(other.width)) {
      throw runtime_error("Box type must match for addition!");
    }
    return Box(this->width + other.width);
  }

  // Overload << operator to display output
  friend ostream &operator<<(ostream &os, const Box &b) {
    os << b.width;
    return os;
  }
};

int main() {
  try {
    Box<int> box1(10);
    Box<int> box2(20);
    Box<int> box3 = box1 + box2;

    cout << "Box 1 width: " << box1 << endl;
    cout << "Box 2 width: " << box2 << endl;
    cout << "Box 3 width: " << box3 << endl;

    Box<float> box4(5.5);
    Box<float> box5(4.5);
    Box<float> box6 = box4 + box5;

    cout << "Box 4 width: " << box4 << endl;
    cout << "Box 5 width: " << box5 << endl;
    cout << "Box 6 width: " << box6 << endl;
  } catch (const exception &e) {
    cerr << "Error: " << e.what() << endl; // Display error message
  }
}
