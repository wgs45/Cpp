#include <iostream>

class Classroom {
public:
  double length;
  double breadth;
  double height;

  double calculate_area() { return length * breadth; }

  double calculate_volume() { return length * breadth * height; }
};

int main() {
  Classroom r1, r2;

  // assign values
  r1.length = 42.5;
  r1.breadth = 30.8;
  r1.height = 19.2;

  // calculate area
  std::cout << "Area: ";
  std::cout << r1.calculate_area();
  std::cout << std::endl;

  // calculate volume
  std::cout << "Volume: ";
  std::cout << r1.calculate_volume();
  std::cout << std::endl;

  return 0;
}
