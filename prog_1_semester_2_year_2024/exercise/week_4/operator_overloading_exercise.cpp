#include <iostream>

class Pasta {
private:
  int quantity;

public:
  // constructor
  Pasta() : quantity(0) {}

  // Overloading the >> operator to take input
  friend std::istream &operator>>(std::istream &input, Pasta &p) {
    std::cout << "Enter the quantity of pasta: ";
    input >> p.quantity;
    return input;
  }

  // Overloading the << operator to display output
  friend std::ostream &operator<<(std::ostream &output, const Pasta &p) {
    output << "Quantity of pasta: " << p.quantity;
    return output;
  }

  // Overloading the + operator to add two pasta objects
  Pasta operator+(const Pasta &p) const {
    Pasta temp;
    temp.quantity = this->quantity + p.quantity;
    return temp;
  }
};

int main() {
  Pasta pasta_1, pasta_2, pasta_3;

  std::cin >> pasta_1;
  std::cin >> pasta_2;

  pasta_3 = pasta_1 + pasta_2;

  std::cout << "Pasta 1: " << pasta_1 << std::endl;
  std::cout << "pasta 2: " << pasta_2 << std::endl;
  std::cout << "pasta 3: " << pasta_3 << std::endl;

  return 0;
}
