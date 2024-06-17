#include <iostream>

class Classroom {
private:
  double length;
  double breadth;
  double height;

public:
  void init_data(double l, double b, double h) {
    length = l;
    breadth = b;
    height = h;
  }

  double calculate_area() { return length * breadth; }

  double calculate_volume() { return length * breadth * height; }
};

int main() {
  Classroom r1;

  r1.init_data(42.5, 30.8, 19.2);

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
