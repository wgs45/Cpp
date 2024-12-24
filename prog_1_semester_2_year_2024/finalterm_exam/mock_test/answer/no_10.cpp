#include <iostream>
using namespace std;

template <typename T> class Polygon {
public:
  T width, height;

  virtual T area() = 0;
  virtual void setValues(T w, T h) = 0;
};

template <typename T> class Rectangle : public Polygon<T> {
public:
  void setValues(T w, T h) {
    this->width = w;
    this->height = h;
  }
  T area() { return this->width * this->height; }
};

template <typename T> class Triangle : public Polygon<T> {
public:
  void setValues(T w, T h) {
    this->width = w;
    this->height = h;
  }
  T area() { return this->width * this->height * 0.5; }
};

int main() {
  double a = 2.5, b = 6;

  Rectangle<double> rectangle;
  Triangle<double> triangle;
  Polygon<double> *poly1 = &rectangle;
  Polygon<double> *poly2 = &triangle;

  poly1->setValues(a, b);
  poly2->setValues(a, b);

  cout << poly1->area() << endl;
  cout << poly2->area() << endl;

  return 0;
}
