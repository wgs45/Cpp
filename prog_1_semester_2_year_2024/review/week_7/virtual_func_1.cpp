#include <iostream>
using namespace std;

class Base {
public:
  virtual void func_1() {
    // Initialize pure virtual function
    cout << "Base function 1" << endl;
  }
};

class Derived : public Base {
public:
  virtual void func_1() override { cout << "Derived function 1 " << endl; }
};

int main() {
  Base base_1;
  base_1.func_1();

  Derived derived_1;
  Base *derived_2 = new Derived();

  derived_2->func_1();

  return 0;
}
