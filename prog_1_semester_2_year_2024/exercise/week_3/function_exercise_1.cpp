#include <iostream>

// Base classs
class Base {
protected:
  int protected_var;

public:
  Base() : protected_var(0) {}

  void display() {
    std::cout << "Base class protected_var: " << protected_var << std::endl;
  }
};

// Derived class 1
class Derived_1 : public Base {
public:
  void modify_and_display() {
    protected_var = 10;
    std::cout << "Derived_1 class modified protected_var: " << protected_var
              << std::endl;
  }
};

// Derived class 2
class Derived_2 : public Base {
public:
  void modify_and_display() {
    protected_var = 20;
    std::cout << "Derived_2 class modified protected_var: " << protected_var
              << std::endl;
  }
};

int main() {
  Derived_1 obj_1;
  Derived_2 obj_2;

  std::cout << "Calling Derived_1 modify_and_display function: " << std::endl;
  obj_1.modify_and_display();

  std::cout << std::endl;

  std::cout << "Calling Derived_2 modify_and_display function: " << std::endl;
  obj_2.modify_and_display();

  return 0;
}
