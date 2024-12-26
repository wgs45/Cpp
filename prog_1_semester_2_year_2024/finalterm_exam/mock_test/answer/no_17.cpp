#include <cmath>
#include <iostream>

template <typename T> class Point {
private:
  T x, y;

public:
  Point(T x, T y) : x(x), y(y) {}

  T getX() const { return x; }
  T getY() const { return y; }

  void display() const { std::cout << x << ", " << y << std::endl; }
};

template <typename T> T distance(const Point<T> &a, const Point<T> &b) {
  T differenceX = a.getX() - b.getX();

  T differenceY = a.getY() - a.getY();

  T dist = std::sqrt(differenceX * differenceX + differenceY * differenceY);

  if (std::is_integral<T>::value) {
    return static_cast<T>(dist);
  }
  return dist;
}

int main() {
  Point<int> p1(3, 4);
  Point<int> p2(6, 8);

  std::cout << "Distance between: ";
  p1.display();
  std::cout << " and ";
  p2.display();
  std::cout << " is: " << distance(p1, p2) << std::endl;

  Point<double> p3(3.2, 4.5);
  Point<double> p4(6.7, 8.9);
  std::cout << "Distance between ";
  p3.display();
  std::cout << " and ";
  p4.display();
  std::cout << " is: " << distance(p3, p4) << std::endl;

  return 0;
}
