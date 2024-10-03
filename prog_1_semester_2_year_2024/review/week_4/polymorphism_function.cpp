#include <iostream>
using namespace std;

class Vehicle {
protected:
  int x;

public:
  Vehicle() { x = 0; }
  void Run() { x++; }
};

class Train : public Vehicle {
public:
  void Run() { x++; }
  void Run(int x_) { x += x_; }
  void show_pos() {
    cout << "Train at: ";
    cout << "(" << x << ")" << endl;
  }
};

class Car : public Vehicle {
protected:
  int y;

public:
  Car() {
    x = 0;
    y = 0;
  }

  void Run() {
    x++;
    y++;
  }

  void show_pos() {
    cout << "Car at: ";
    cout << "(" << x << ", " << y << ")" << endl;
  }
};

class Flying_car : public Car {
protected:
  int z;

public:
  Flying_car() {
    x = 0;
    y = 0;
    z = 0;
  }

  void Run() {
    x++;
    z++;
  }

  void Up(int x) { z = z + x; }
  void show_pos() {
    cout << "Flying Car at: ";
    cout << "(" << x << ", " << y << ", " << z << ")" << endl;
  }
};

int main() {
  Train train_1;
  train_1.Run(19);
  train_1.Run();
  train_1.show_pos();

  Car car_1;
  car_1.Run();
  car_1.Run();
  car_1.show_pos();

  Flying_car flying_car_1;
  flying_car_1.Run();
  flying_car_1.Up(3);
  flying_car_1.show_pos();

  return 0;
}
