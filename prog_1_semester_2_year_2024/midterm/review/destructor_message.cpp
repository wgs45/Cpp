#include <iostream>
using namespace std;

class Base {
public:
  Base() { cout << "Constructor is called!" << endl; }

  ~Base() { cout << "Destructor is called!" << endl; }
};

int main() {
  Base *base_1 = new Base[2];
  delete[] base_1;

  return 0;
}
