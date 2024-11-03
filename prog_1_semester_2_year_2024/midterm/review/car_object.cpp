#include <iostream>
using namespace std;

class Car {
private:
  int x, y;

public:
  Car(int x_coordinate, int y_coordinate) : x(x_coordinate), y(y_coordinate) {}

  void display() { cout << "Car position at: " << x << ", " << y << endl; }
};

int main() {
  Car obj_1(10, 20);
  obj_1.display();

  return 0;
}
