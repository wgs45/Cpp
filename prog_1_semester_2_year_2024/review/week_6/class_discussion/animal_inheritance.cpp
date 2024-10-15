#include <iostream>
using namespace std;

class Animal {
public:
  virtual void make_sound() { cout << "Animal makes a sound" << endl; }
};

class Dog : public Animal {
public:
  virtual void make_sound() override { cout << "Woof!" << endl; }
};

class Cat : public Animal {
public:
  virtual void make_sound() override { cout << "Meow!" << endl; }
};

int main() {
  Animal *animal_1 = new Animal();
  Dog *dog_1 = new Dog();
  Cat *cat_1 = new Cat();

  animal_1->make_sound();
  dog_1->make_sound();
  cat_1->make_sound();

  return 0;
}
