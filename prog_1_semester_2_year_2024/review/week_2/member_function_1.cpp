#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Car {
  char name[100];
  int x;
  int y;

public:
  Car();
  Car(char *n, int cx, int cy);
  char *get_name();
  void set_pos_x(int cx);
  void set_pos_y(int cy);
  int get_pos_x();
  int get_pos_y();
};

Car::Car() {
  x = 0;
  y = 0;
}

Car::Car(char *n, int cx, int cy) {
  strcpy(name, n);
  x = cx;
  y = cy;
}

char *Car::get_name() { return name; }
void Car::set_pos_x(int cx) { x = cx; }
void Car::set_pos_y(int cy) { y = cy; }
int Car::get_pos_x() { return x; }
int Car::get_pos_y() { return y; }

int main() {
  Car c("Tesla", 90, 100);

  cout << "Car name is: " << c.get_name() << endl;
  c.set_pos_x(30);
  cout << "Car position X is: " << c.get_pos_x() << endl;
  cout << "Car position Y is: " << c.get_pos_y() << endl;

  return 0;
}
