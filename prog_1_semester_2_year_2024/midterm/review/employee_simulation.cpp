#include <iostream>
using namespace std;

class Employee {
public:
  virtual void do_work() = 0; // Pure virtual function
  virtual ~Employee() {}      // Destructor
};

class Manager : public Employee {
public:
  void do_work() override { cout << "Manager: planning" << endl; }
};

class Engineer : public Employee {
public:
  void do_work() override { cout << "Engineer: coding" << endl; }
};

int main() {
  Manager *manager_1 = new Manager();
  Engineer *engineer_1 = new Engineer();

  manager_1->do_work();
  engineer_1->do_work();

  delete manager_1;
  delete engineer_1;

  return 0;
}
