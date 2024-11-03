#include <iostream>
using namespace std;

class Shape {
public:
  virtual double area() const = 0; // Pure virtual function
  virtual ~Shape() {}              // Destructor
};

// Derived class
class Rectangle : public Shape {
private:
  double length, width;

public:
  Rectangle(double l, double w) : length(l), width(w) {}

  double area() const override { return length * width; }
};

// Derived class
class Circle : public Shape {
private:
  double radius;

public:
  Circle(double r) : radius(r) {}

  double area() const override { return M_PI * radius * radius; }
};

int main() {
  Rectangle rectangle_1(5.0, 3.0);
  Circle circle_1(4.0);

  cout << "Rectangle area: " << rectangle_1.area() << endl;
  cout << "Circle area: " << circle_1.area() << endl;

  return 0;
}
