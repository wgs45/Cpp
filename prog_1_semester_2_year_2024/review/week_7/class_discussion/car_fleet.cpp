#include <iostream>
using namespace std;

class Car {
private:
  friend void Show(Car &);
  int x, y;

public:
  Car() {
    x = 0;
    y = 0;
  }

  Car(int x, int y) {
    this->x = x;
    this->y = y;
  }
};

void Show(Car &c) { cout << "Position: " << c.x << ", " << c.y << endl; }

int main() {
  Car car_1[3];
  Car *car_2 = new Car[3];

  int i;
  for (i = 0; i < 3; i++) {
    car_1[i] = Car(i * 2, i * 3);
    car_2[i] = Car(i * 4, i * 5);
  }

  for (i = 0; i < 3; i++) {
    Show(car_1[i]);
    Show(car_2[i]);
  }

  return 0;
}
