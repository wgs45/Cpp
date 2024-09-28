#include <iostream>
using namespace std;

class Grandpa {
protected:
  int x;
  void Go() { x++; }
  void Back() { x--; }
};

class Father : public Grandpa {
public:
  void Go() { x += 2; }
  void Back() { x -= 2; }
};

class Me : public Father {
public:
  Me() { x = 0; }
  Go() { Grandpa::Go(); }
  void show() { cout << x << endl; }
};

int main() {
  Me obj_1;

  obj_1.Go();
  obj_1.show();
  obj_1.Back();
  obj_1.show();

  return 0;
}
