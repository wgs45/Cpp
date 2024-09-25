#include <iostream>
using namespace std;

class Vehicle {
private:
  int x;
  int y;

public:
  // Constructor
  Vehicle() {
    x = 0;
    y = 0;
  }

  // Destructor
  ~Vehicle() { cout << "Success" << endl; }
  void Run() { x++; }
  int get_pos_x() { return x; }
  int get_pos_y() { return y; }
  int move_pos_x() { x++; }
  int move_pos_y() { y++; }
};

class Car : public Vehicle {
public:
  void Run() {
    move_pos_x();
    move_pos_y();
  }
};

int main() {
  Car obj_1;

  cout << obj_1.get_pos_x() << " " << obj_1.get_pos_y() << endl;

  // Because the Run() function is never called so the value remains the same
  cout << obj_1.get_pos_x() << " " << obj_1.get_pos_y() << endl;

  return 0;
}
