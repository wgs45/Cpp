#include <iostream>
using namespace std;

class Animal {
  double weight;
  double tall;
  double sleep_hour;
  int x;
  int y;
};

class Dog : public Animal {
  friend class Cat;
  int bark_sound_id;

  void bark() { cout << "Wow" << endl; }
};

class Cat : public Animal {
public:
  void bark() {
    Dog obj_1;
    if (obj_1.bark_sound_id == 1) {
      cout << "Meow" << endl;
    }
  }
};

int main() {
  Cat obj_1;
  obj_1.bark();

  return 0;
}
