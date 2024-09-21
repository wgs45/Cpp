#include <iostream>
using namespace std;

class Car {
public:
  int x;
  int y;

  Car() {
    x = 0;
    y = 0;
  }
};

int main() {
  Car c;

  cout << "Car created at: (" << c.x << ", " << c.y << ")";

  c.x = 20;
  c.y = 10;

  cout << endl;
  cout << "Car is now at : (" << c.x << ", " << c.y << ")" << endl;

  return 0;
}
