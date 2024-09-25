#include <iostream>
using namespace std;

class Vehicle {
protected:
  int x, y;
};

class Car : public Vehicle {};

class Flying_car : public Car {
private:
  int z;

public:
  Flying_car(int x_, int y_, int z_) {
    x = x_;
    y = y_;
    z = z_;
  }

  void show_pos() {
    cout << "Flying car at: ";
    cout << "(" << x << ", " << y << ", " << z << ")" << endl;
  }
};

int main() {
  Flying_car obj_1(12, 23, 34);

  obj_1.show_pos();

  return 0;
}
