#include <iostream>
using namespace std;

class Box {
private:
  int width, height;

public:
  Box() {
    width = 0;
    height = 0;
  }

  void set_value(int x, int y) {
    width = x;
    height = y;
  }

  // Overloading = operator to store data
  void operator=(Box &box_1) {
    width = box_1.width;
    height = box_1.height;
  }

  void show() { cout << "Result: " << width << ", " << height << endl; }
};

int main() {
  Box obj_1;

  obj_1.set_value(3, 5);
  Box obj_2;

  obj_2 = obj_1;
  obj_2.show();

  return 0;
}
