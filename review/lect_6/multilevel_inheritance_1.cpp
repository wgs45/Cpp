#include <iostream>
using namespace std;

class Vehicle {
public:
  Vehicle() { cout << "This is a Vehicle" << endl; }
};

class FourWheeler : public Vehicle {
public:
  FourWheeler() { cout << "This Vehicle contain 4 wheels" << endl; }
};

class Car : public FourWheeler {
public:
  Car() { cout << "A car has 4 wheels" << endl; }
};

int main() {
  // Invoke the constructors
  Car obj;

  return 0;
}
