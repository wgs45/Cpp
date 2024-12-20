#include <iostream>
using namespace std;

template <typename T> class Box {
private:
  T width;

public:
  Box() {}
  Box(T w) { this->width = w; }

  Box operator+(Box &b) const {
    Box t;
    t.width = this->width + b.width;
    return t;
  }

  friend ostream &operator<<(ostream &os, Box &b) {
    os << b.width;
    return os;
  }
};

int main() {
  Box<double> a(2.3), b(4.5);
  Box<double> c = a + b;
  cout << c << endl;

  return 0;
}
