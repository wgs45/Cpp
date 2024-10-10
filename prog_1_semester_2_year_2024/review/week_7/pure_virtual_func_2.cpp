#include <iostream>
using namespace std;

class Animal {
public:
  // Initialize pure virtual function
  virtual void eat() = 0;
};

class Dog : public Animal {
public:
  // Overriding the pure virtual function
  virtual void eat() override { cout << "Dog: I can eat meat!" << endl; }
};

class Cat : public Animal {
public:
  // Overriding the pure virtual function
  virtual void eat() override { cout << "Cat: I can eat fish!" << endl; }
};

class Unknown : public Animal {
  // Abstract class
};

int main() {
  Animal *animal;

  Dog dog;
  Cat cat;
  // Unknown u; // error because it is an abstract class

  animal = &dog;
  animal->eat();

  animal = &cat;
  animal->eat();

  return 0;
}
