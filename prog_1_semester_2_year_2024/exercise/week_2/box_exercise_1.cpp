#include <iostream>
using namespace std;

class Box {
private:
  double length;
  double width;

public:
  // Constructor
  Box(double l = 0, double w = 0) : length(l), width(w) {}

  // Overload + operator for addition of two box objects
  Box operator+(const Box &b) {
    return Box(length + b.length, width + b.width);
  }

  // Overload - operator for subtraction of two box objects
  Box operator-(const Box &b) {
    double new_width = (width > b.width) ? width - b.width : b.width - width;
    return Box(length - b.length, new_width);
  }

  // Overload * operator for multiplication of Box by a constant
  Box operator*(double constant) {
    return Box(length * constant, width * constant);
  }

  // Overload / operator for division of Box by a constant
  Box operator/(double constant) {
    if (constant == 0) {
      throw invalid_argument("Division by zero is not allowed.");
    }
    return Box(length / constant, width / constant);
  }

  void display() const {
    cout << "Length: " << length << ", Width: " << width << endl;
  }
};

int main() {
  // Create two box objects
  Box box_1(10, 5);
  Box box_2(0, 3);

  // Perform addition
  Box sum_box = box_1 + box_2;
  cout << "After addition: ";
  sum_box.display();

  // Perform subtraction
  Box sub_box = box_1 - box_2;
  cout << "After subtraction: ";
  sub_box.display();

  // Perform multiplication by a constant
  double constant = 2;
  Box mul_box = box_1 * constant;
  cout << "After multiplication by " << constant << ": ";
  mul_box.display();

  // Perform division by a constant
  Box div_box = box_1 / constant;
  cout << "After division by " << constant << ": ";
  div_box.display();

  return 0;
}
