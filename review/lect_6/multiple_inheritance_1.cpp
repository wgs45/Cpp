#include <iostream>
using namespace std;

class Vehicle {
public:
  Vehicle() { cout << "This is a Vehicle." << endl; }
};

class FourWheeler {
public:
  FourWheeler() { cout << "This Vehicle has 4 wheels." << endl; }
};

class Car : public Vehicle, public FourWheeler {
  // Example...
};

int main() {
  // Invoke the contructors
  Car obj;

  return 0;
}
