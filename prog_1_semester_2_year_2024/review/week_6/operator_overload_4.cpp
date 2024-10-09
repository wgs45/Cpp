#include <iostream>
using namespace std;

class Cat {
private:
  int age;

public:
  Cat() { age = 0; }

  Cat operator!() {
    age++;
    return *this;
  }

  Cat operator~() {
    age = age * 3;
    return *this;
  }

  Cat operator=(Cat cat_1) { return cat_1; }

  void set_age(int age_num) { age = age_num; }

  void show() { cout << "Age: " << age << endl; }
};

int main() {
  Cat cat_1;

  cat_1.set_age(5);

  cat_1 = !cat_1;
  cat_1.show();

  cat_1 = ~cat_1;
  cat_1.show();

  return 0;
}
