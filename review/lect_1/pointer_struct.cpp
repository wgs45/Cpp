#include <iostream>

struct Distance {
  int feet;
  float inch;
};

int main() {
  Distance *ptr, d;

  ptr = &d;

  std::cout << "Enter feet: ";
  std::cin >> (*ptr).feet;
  std::cout << "Enter inch: ";
  std::cin >> (*ptr).inch;

  std::cout << "Displaying information: " << std::endl;
  std::cout << "Distance: " << (*ptr).feet << ", Feet: " << (*ptr).inch
            << std::endl;

  return 0;
}
