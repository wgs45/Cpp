#include <iostream>
using namespace std;

template <class T> class Polygon {
public:
  T width, height;

  virtual T area() = 0;
  virtual void setValues(T w, T h) = 0;
};

template <class T> class Rectangle : public Polygon<T> {
public:
  void setValues(T w, T h) {
    this->width = w;
    this->height = h;
  }
  T area() { return this->width * this->height; }
};

template <class T> class Triangle : public Polygon<T> {
public:
  void setValues(T w, T h) {
    this->width = w;
    this->height = h;
  }
  T area() { return this->width * this->height * 0.5; }
};

int main() {

  double a = 2.5, b = 6;
  Rectangle<double> rect;
  Triangle<double> trgl;
  Polygon<double> *ppoly1 = &rect;
  Polygon<double> *ppoly2 = &trgl;
  ppoly1->setValues(a, b);
  ppoly2->setValues(a, b);

  cout << ppoly1->area() << endl;
  cout << ppoly2->area() << endl;
  return 0;
}
