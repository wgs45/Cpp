#include <iostream>
using namespace std;

class Base {
public:
  virtual void func_1() = 0; // This is a pure virtual function
};

class Derived : public Base {
public:
  // Overriding the pure virtual function
  virtual void func_1() override { cout << "Derived function 1" << endl; }
};

int main() {
  Derived derived_1;

  derived_1.func_1();

  Base *derived_2 = new Derived();
  derived_2->func_1();

  return 0;
}
