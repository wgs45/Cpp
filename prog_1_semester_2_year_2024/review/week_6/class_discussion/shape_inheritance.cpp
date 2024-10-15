#include <iostream>
using namespace std;

class Shape {
private:
  double width, height;

public:
  // Constructor for initializing width and height
  Shape(double w, double h) : width(w), height(h) {}

  // Getter Function to provide access to width and height
  double get_width() const { return width; }

  double get_height() const { return height; }

  // Virtual function for area (to be overriden by derived class)
  virtual double area() const = 0;
};

class Rectangle : public Shape {
public:
  // Constructor calls the base class Constructor
  Rectangle(double w, double h) : Shape(w, h) {}

  // Override area function to reactangle
  double area() const override { return get_width() * get_height(); }
};

class Triangle : public Shape {
public:
  // Constructor calls the base class Constructor
  Triangle(double w, double h) : Shape(w, h) {}

  // Override area function for triangle (1/2 * base * height)
  double area() const override { return 0.5 * get_width() * get_height(); }
};

int main() {
  Rectangle rectangle_1(3.5, 2);
  Triangle triangle_1(3.2, 5);

  cout << "Rectangle area: " << rectangle_1.area() << endl;
  cout << "Triangle area: " << triangle_1.area() << endl;

  return 0;
}
