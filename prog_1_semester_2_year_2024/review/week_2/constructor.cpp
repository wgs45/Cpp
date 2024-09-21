#include <iostream>
#include <string.h>
using namespace std;

class Car {
public:
  char name[100];
  int x;
  int y;

  Car() {
    x = 0;
    y = 0;
  }

  Car(char *n, int cx, int cy) {
    strcpy(name, n);
    x = cx;
    y = cy;
  }
};

int main() {
  Car c("Tesla", 90, 100);

  cout << "Car " << c.name;
  cout << " is now at: (" << c.x << ", " << c.y << ")" << endl;

  return 0;
}
