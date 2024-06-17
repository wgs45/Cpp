#include <iostream>

struct Rect {
  double x1;
  double x2;
  double y1;
  double y2;
};

int main() {
  Rect value;
  double result = 0;

  std::cout << "Enter value: ";
  std::cin >> value.x1 >> value.y1 >> value.x2 >> value.y2;

  result = abs(value.x2 - value.x1) * abs(value.y2 - value.y1);
  std::cout << "Result: " << result << std::endl;

  return 0;
}
