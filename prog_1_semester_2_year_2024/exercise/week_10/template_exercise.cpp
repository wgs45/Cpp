#include <iostream>
using namespace std;

template <typename T, typename S>
// decltype = declared type of an expression
auto add(T input_1, S input_2) -> decltype(input_1 + input_2) {
  return input_1 + input_2;
}

int main() {
  cout << add(3, 9) << endl;   // integer
  cout << add(3.5, 9) << endl; // float
  cout << add(3, 9.5) << endl; // float

  return 0;
}
