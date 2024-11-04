#include <iostream>
using namespace std;

class Ancestor {
public:
  Ancestor() { cout << "Ancestor is called" << endl; }
};

class Parent_1 : virtual public Ancestor {
public:
  Parent_1() { cout << "Parent_1 is called" << endl; }
};

class Parent_2 : virtual public Ancestor {
public:
  Parent_2() { cout << "Parent_2 is called" << endl; }
};

class Child : public Parent_1, Parent_2 {
public:
  Child() { cout << "Child is called" << endl; }
};

int main() {
  Child *child = new Child();
  delete child;

  return 0;
}
