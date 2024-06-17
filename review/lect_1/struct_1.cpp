#include <iostream>

struct Person {
  char name[50];
  int age;
  float salary;
};

void display_data(Person);

int main() {
  Person p;

  std::cout << "Enter fullname: ";
  std::cin.get(p.name, 50);
  std::cout << "Enter age: ";
  std::cin >> p.age;
  std::cout << "Enter salary: ";
  std::cin >> p.salary;

  std::cout << std::endl;
  display_data(p);

  return 0;
}

void display_data(Person p) {
  std::cout << "Displaying information" << std::endl;
  std::cout << "Name: " << p.name << std::endl;
  std::cout << "Age: " << p.age << std::endl;
  std::cout << "Salary: " << p.salary << std::endl;
}
