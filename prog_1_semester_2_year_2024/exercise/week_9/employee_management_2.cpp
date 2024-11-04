#include <iostream>
#include <string>
using namespace std;

// Creating unique id for every Employee

class Employee {
public:
  int id;
  string name;
  static int next_id;

  Employee(const string &name) : id(next_id++), name(name) {}

  void display_info() { cout << "Name & ID: " << name << ", " << id << endl; }

  static int get_next_id() { return next_id; }
};

int Employee::next_id = 1; // Initialize next id value

int main() {
  Employee employee_1("Alpha"), employee_2("Beta"), employee_3("Charlie");

  employee_1.display_info();
  employee_2.display_info();
  employee_3.display_info();

  cout << "Mext available ID: " << Employee::get_next_id() << endl;

  return 0;
}
