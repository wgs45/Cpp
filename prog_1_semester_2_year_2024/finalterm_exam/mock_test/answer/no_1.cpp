#include <iostream>
using namespace std;

// Template function to add two inputs of potentially different types
template <typename T, typename S> T add(T input_1, S input_2) {
  return input_1 + input_2;
}

int main() {
  // Test the add function with different types of inputs
  cout << add(1, 2) << endl;      // Adding two integers
  cout << add(1.1, 2.2) << endl;  // Adding two doubles
  cout << add(5.2f, 3.1) << endl; // Adding a float and a double
  cout << add(4, 3.2) << endl;    // Adding an integer and a double

  return 0;
}
