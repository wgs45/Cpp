#include <iostream>
using namespace std;

class Point {
private:
  double x, y;

public:
  Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}

  // setters
  void set_x(double x) { this->x = x; }

  void set_y(double y) { this->y = y; }

  // getters
  double get_x() const { return x; }

  double get_y() const { return y; }
};

class Line {
private:
  Point point_1, point_2;

public:
  // Parameterized constructor
  Line(const Point &p1, const Point &p2) : point_1(p1), point_2(p2) {}

  double calculate_length() const {
    return sqrt(pow(point_2.get_x() - point_1.get_x(), 2) +
                pow(point_2.get_y() - point_1.get_y(), 2));
  }
};

int main() {
  Point point_1(1.0, 2.0);
  Point point_2(4.0, 6.0);

  Line line(point_1, point_2);
  cout << "Result: " << line.calculate_length() << endl;

  return 0;
}
