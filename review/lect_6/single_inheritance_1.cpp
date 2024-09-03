#include <iostream>
using namespace std;

class Vehicle {
public:
  Vehicle() { cout << "This is a vehicle." << endl; }
};

class Car : public Vehicle {
  // Example...
};

int main() {
  // invoke the constructors
  Car obj;

  return 0;
}
