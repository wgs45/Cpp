#include <iostream>
using namespace std;

class Box {
private:
  double length, width;

public:
  // Parametirzed constructor
  Box(double l = 0, double w = 0) : length(l), width(w) {}

  Box operator+(const Box &b) {
    return Box(length + b.length, width + b.width);
  }

  Box operator-(const Box &b) {
    double new_width = (width - b.width) ? width - b.width : b.width - width;
    return Box(length - b.length, new_width);
  }

  Box operator*(double constant) {
    return Box(length * constant, width * constant);
  }

  Box operator/(double constant) {
    if (constant == 0) {
      cout << "Division by zero is not allowed!" << endl;
    }
    return Box(length / constant, width / constant);
  }

  void display() {
    cout << "Length & width: " << length << ", " << width << endl;
  }
};

int main() {
  Box box_1(10, 5);
  Box box_2(0, 3);

  Box sum_box = box_1 + box_2;
  cout << "After addition: ";
  sum_box.display();

  Box sub_box = box_1 - box_2;
  cout << "After subtraction: ";
  sub_box.display();

  double constant = 2;
  Box mul_box = box_1 * 2;
  cout << "After multiplication: ";
  mul_box.display();

  Box div_box = box_1 / 2;
  cout << "After division: ";
  div_box.display();
}
