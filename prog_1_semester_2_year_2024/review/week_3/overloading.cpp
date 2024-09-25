#include <iostream>
#include <math.h>
using namespace std;

class Car {
private:
  int x;
  int y;

public:
  Car() {
    x = 0;
    y = 0;
  }

  Car(int x_, int y_) {
    x = x_;
    y = y_;
  }

  void set_pos(int x_) {
    x = x_;
    y = 0;
  }

  void set_pos(int x_, int y_) {
    x = x_;
    y = y_;
  }

  void set_pos(double x_, double y_) {
    x = round(x_);
    y = round(y_);
  }

  void show_pos() { cout << x << "," << y << endl; }
};

int main() {
  Car obj_1;
  Car obj_2(3, 4);

  cout << "Object 1 initial value: ";
  obj_1.show_pos();
  cout << "[Edit] Set obj_1 position to (12.5, 13.6)" << endl;
  obj_1.set_pos(12.5, 13.6);
  cout << "[Output] Display obj_1 position: ";
  obj_1.show_pos();

  cout << endl;

  cout << "Object 2 initial value: ";
  obj_2.show_pos();
  cout << "[Edit] Set obj_2 position to (5,6)" << endl;
  obj_2.set_pos(5, 6);
  cout << "[Output] Display obj_2 position: ";
  obj_2.show_pos();

  return 0;
}
