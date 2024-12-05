#include <iostream>
using namespace std;

template <class T> class Complex {
public:
  T real, imaginary;

  Complex() {}
  Complex(T r, T i) {
    real = r;
    imaginary = i;
  }

  Complex<T> operator+(Complex<T> c) {
    return Complex(this->real + c.real, this->imaginary + c.imaginary);
  }

  void show() { cout << real << ", " << imaginary << endl; }
};

int main() {
  Complex<double> set_1(3.5, 2.4);
  Complex<double> set_2(4.5, 2.3);
  Complex<double> set_3;

  set_3 = set_1 + set_2;
  set_3.show();

  return 0;
}
