#include <iostream>
using namespace std;

// Define a Complex class
class Complex {
private:
  double real;      // Real part of the complex number
  double imaginary; // Imaginary part of the complex number

public:
  // Constructor to initialize real and imaginary parts
  Complex(double r = 0, double i = 0) : real(r), imaginary(i) {}

  // Overload the + operator to add two complex numbers
  Complex operator+(const Complex &other) {
    // Add corresponding real and imaginary parts
    return Complex(real + other.real, imaginary + other.imaginary);
  }

  // Method to display the complex number
  void show() { cout << real << " + " << imaginary << "i" << endl; }
};

int main() {
  // Create two complex number objects
  Complex ia(3.5, 2.4); // Complex number 3.5 + 2.4i
  Complex ib(4.5, 2.3); // Complex number 4.5 + 2.3i

  // Add the two complex numbers using the overloaded + operator
  Complex ic = ia + ib;

  // Display the result
  ic.show(); // Output will be: 8.0 + 4.7i

  return 0;
}
