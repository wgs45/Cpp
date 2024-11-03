#include <iostream>
using namespace std;

class Base {
protected:
  int protected_var;

public:
  Base() : protected_var(0) {}

  void display() { cout << "Protected variable: " << protected_var << endl; }
};

class Derived_1 : public Base {
public:
  void change_value() { protected_var = 10; }
};

class Derived_2 : public Base {
public:
  void change_value() { protected_var = 20; }
};

int main() {
  Derived_1 obj_1;
  Derived_2 obj_2;

  obj_1.change_value();
  obj_1.display();

  obj_2.change_value();
  obj_2.display();

  return 0;
}
