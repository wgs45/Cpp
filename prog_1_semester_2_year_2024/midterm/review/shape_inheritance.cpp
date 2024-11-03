#include <iostream>
using namespace std;

class Shape {
private:
  double width, height;

public:
  // Parameterized constructor
  Shape(double w, double h) : width(w), height(h) {}

  // Declare a getter function
  double get_width() const { return width; }

  double get_height() const { return height; }

  // Virtual function for area (to be overriden by derived class)
  virtual double area() const = 0;
};

class Rectangle : public Shape {
public:
  Rectangle(double w, double h) : Shape(w, h) {}

  // Overriding pure virtual function
  double area() const override { return get_width() * get_height(); }
};

class Triangle : public Shape {
public:
  Triangle(double w, double h) : Shape(w, h) {}

  // Overriding pure virtual function
  double area() const override { return 0.5 * get_width() * get_height(); }
};

int main() {
  Rectangle rectangle_1(3.5, 2);
  Triangle triangle_1(3.2, 5);

  cout << "Rectangle: " << rectangle_1.area() << endl;
  cout << "Triangle: " << triangle_1.area() << endl;

  return 0;
}
