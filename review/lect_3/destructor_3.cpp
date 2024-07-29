#include <iostream>

class rectangle {
  // typedef int unit;

public:
  typedef int unit;

  // constructor to initialize with and height
  rectangle() : width(0), height(0) {}
  rectangle(unit wd, unit ht) : width(wd), height(ht) {}

  void area();
  void set(unit wd, unit ht);

private:
  unit width;
  unit height;
};

void rectangle::set(unit wd, unit ht) {
  width = wd;
  height = ht;
}

void rectangle::area() {
  std::cout << "The area: " << width * height << std::endl;
}

int main() {
  rectangle obj_1, obj_2(2, 5);
  rectangle::unit x, y;

  std::cout << "Enter value: " << std::endl;
  std::cin >> x;
  std::cin >> y;
  obj_1.set(x, y);
  obj_1.area();
  obj_2.area();

  return 0;
}
