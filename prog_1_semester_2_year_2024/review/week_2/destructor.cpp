#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Car {
public:
  char *name;
  int x;
  int y;

  Car() {
    x = 0;
    y = 0;
  }

  // Constructor
  Car(char *n, int cx, int cy) {
    name = (char *)malloc(strlen(n) * sizeof(char));
    strcpy(name, n);
    x = cx;
    y = cy;
  }

  // Destructor
  ~Car() { free(name); }
};

int main() {
  Car c("Tesla", 90, 100);

  cout << "Car " << c.name;
  cout << " is now at: (" << c.x << ", " << c.y << ")" << endl;
  ;

  return 0;
}
