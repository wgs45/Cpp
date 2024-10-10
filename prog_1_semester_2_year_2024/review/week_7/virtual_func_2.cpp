#include <iostream>
using namespace std;

class Animal {
public:
  // Initialize virtual function with default implementation
  virtual void eat() { cout << "I eat food!" << endl; }
  // virtual void eat() = 0;
};

class Dog : public Animal {
public:
  // Overriding pure virtual function
  virtual void eat() override { cout << "Dog: I eat meat!" << endl; }
};

class Cat : public Animal {
public:
  // Overriding pure virtual funtion
  virtual void eat() override { cout << "Cat: I eat fish!" << endl; }
};

class Unknown : public Animal {
  // Not abstract class anymore bacause unknown class inherits the default
  // behavior "eat()" from the class Animal
};

int main() {
  Animal *animal;

  Dog dog;
  Cat cat;
  Unknown unknown;

  animal = &dog;
  animal->eat();

  animal = &cat;
  animal->eat();

  animal = &unknown;
  animal->eat();

  return 0;
}
