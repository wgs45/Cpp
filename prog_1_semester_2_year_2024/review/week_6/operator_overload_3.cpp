#include <iostream>
using namespace std;

class Box {
  int width, height;

public:
  Box() {
    width = 0;
    height = 0;
  }

  Box(int x, int y) {
    width = x;
    height = x;
  }

  int operator==(Box &box_1) {
    if (width == box_1.width) {
      return 1;
    } else {
      return 0;
    }
  }

  void show() { cout << "Result: " << width << ", " << height << endl; }
};

int main() {
  Box box_1(1, 2);
  Box box_2(6, 4);

  if (box_1 == box_2) {
    cout << "Same" << endl;
  } else {
    cout << "Not the same" << endl;
  }

  return 0;
}
