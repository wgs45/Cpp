#include <iostream>
using namespace std;

class Employee {
public:
  int id;
  string name;

  // Parameterized constructor
  Employee(int id, string name) : id(id), name(name) {}
};

class Department {
public:
  string name;
  Employee *employees[10] = {nullptr};
  int employee_count = 0;

  Department(const string &name) : name(name) {}

  void add_employee(Employee *employee) {
    if (employee_count < 10) {
      employees[employee_count++] = employee;
    }
  }

  Employee *find_by_id(int id) {
    int i;
    for (i = 0; i < employee_count; i++) {
      if (employees[i] && employees[i]->id == id) {
        return employees[i];
      }
    }
    return nullptr;
  }
};

int main() {
  Department department("Engineering");

  department.add_employee(new Employee(1, "Alpha"));
  department.add_employee(new Employee(2, "Beta"));
  department.add_employee(new Employee(3, "Charlie"));

  int search_id = 3;
  Employee *employee = department.find_by_id(search_id);
  if (employee) {
    cout << "Employee found: " << employee->name << endl;
  } else {
    cout << "Employee not found" << endl;
  }

  return 0;
}
