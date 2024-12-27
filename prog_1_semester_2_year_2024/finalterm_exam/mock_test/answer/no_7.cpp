#include <iostream>
using namespace std;

template <class T> class Complex {
private:
  T real, imaginary;

public:
  Complex() {}
  Complex(T r, T i) {
    real = r;
    imaginary = i;
  }

  Complex<T> operator+(Complex<T> c) {
    return Complex(this->real + c.real, this->imaginary + c.imaginary);
  }

  void show() { cout << this->real << ", " << this->imaginary << endl; }

  friend ostream &operator<<(ostream &os, Complex<T> &c) {
    os << c.real << ", " << c.imaginary;
    return os;
  }
};

template <class T> void show(Complex<T> c) {
  cout << c.real << ", " << c.imaginary << endl;
}

int main() {
  Complex<double> set_1(3.5, 2.4);
  Complex<double> set_2(4.5, 2.3);
  Complex<double> set_3;

  set_3 = set_1 + set_2;
  cout << set_3 << endl;

  return 0;
}