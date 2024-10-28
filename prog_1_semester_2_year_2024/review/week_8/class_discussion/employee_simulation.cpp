#include <iostream>
using namespace std;

class Employee {
public:
  virtual void do_work() = 0; // Pure virtual function
  virtual ~Employee() {}      // Virtual destructor for polymorphism
};

// Derived class Manager
class Manager : public Employee {
public:
  void do_work() override { cout << "Manager: Planning" << endl; }
};

// Derived class Engineer
class Engineer : public Employee {
public:
  void do_work() override { cout << "Engineer: Coding" << endl; }
};

int main() {
  Employee *employee_1 = new Manager();
  Employee *employee_2 = new Engineer();

  employee_1->do_work();
  employee_2->do_work();

  delete employee_1;
  delete employee_2;

  return 0;
}
