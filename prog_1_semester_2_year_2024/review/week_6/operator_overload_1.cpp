#include <iostream>
using namespace std;

class Box {
  int width, height;

public:
  // Constructor
  Box(int w = 0, int h = 0) {
    width = w;
    height = h;
  }

  // Overloading + operator to add two Box objects
  Box operator+(Box &box_1) {
    Box box_2;
    box_2.width = width + box_1.width;
    box_2.height = height + box_1.height;
    return box_2;
  }

  void show() { cout << "Result: " << width << ", " << height << endl; }
};

int main() {
  Box obj_1(1, 2);
  Box obj_2(3, 4);

  Box obj_3 = obj_1 + obj_2;
  obj_3.show();

  return 0;
}
