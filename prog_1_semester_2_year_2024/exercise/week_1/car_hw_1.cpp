#include <iostream>
using namespace std;

class Car {
private:
  int x;
  int y;

public:
  // Constructor
  Car(int coordinate_x, int coordinate_y) : x(coordinate_x), y(coordinate_y) {}

  // Display the result
  void display_position() const {
    cout << "Car is at position (" << x << ", " << y << ")" << endl;
  }
};

int main() {
  Car myCar(10, 20);

  myCar.display_position();

  return 0;
}
