#include <iostream>
using namespace std;

class Shape {
public:
  string type;

protected:
  double parameter; // this will store the value of radius
};

class Circle : protected Shape {
private:
  double area = 0.0;

public:
  void setRadius(double radius) { parameter = radius; }

  void computeArea() {
    area = M_PI * parameter * parameter; // Area = Pi * r^2
  }

  // Retyrn the area of the Circle
  double getArea() { return area; }
};

int main() {
  Circle obj;
  obj.setRadius(5.0); // Set radius to 5.0 units
  obj.computeArea();
  cout << "Area: " << obj.getArea() << endl;

  return 0;
}
