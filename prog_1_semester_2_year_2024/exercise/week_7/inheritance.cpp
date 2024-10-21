#include <iostream>
using namespace std;

class Base {
protected:
  int protected_var;

public:
  Base() : protected_var(0) {} // initialize proteccted variable to 0

  void display() { cout << "Protected variable: " << protected_var << endl; }
};

class Derived_1 : public Base {
public:
  // Override function to change the value of protected variable
  void change_value() { protected_var = 10; }
};

class Derived_2 : public Base {
public:
  // Override function to change the value of protected variable
  void change_value() { protected_var = 20; }
};

int main() {
  Derived_1 obj1;
  obj1.change_value();
  obj1.display();

  Derived_2 obj2;
  obj2.change_value();
  obj2.display();

  return 0;
}
