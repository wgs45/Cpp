#include <iostream>
using namespace std;

class Food {
protected:
  double inch;

public:
  Food() { inch = 5; }
};

class Pizza : public Food {
  friend void cut(Pizza &);

public:
  void show() { cout << inch << endl; }
};

void cut(Pizza &p) { p.inch /= 2; }

int main() {
  Pizza obj_1;

  cout << "Value before cut: 5" << endl;
  cut(obj_1);

  cout << "Value after cut by 2 inch: ";
  obj_1.show();

  return 0;
}
