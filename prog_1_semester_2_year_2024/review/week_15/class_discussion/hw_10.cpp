// hw 10 default answer (straightforward answer)
#include <iostream>
using namespace std;

template <class T> class Box {
private:
  T width;

public:
  Box() {}
  Box(T w) { this->width = w; }
  Box operator+(Box &b) {
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
  Box<double> a(3.5), b(4.6);
  Box<double> c = a + b;
  cout << c << endl;
  return 0;
}
