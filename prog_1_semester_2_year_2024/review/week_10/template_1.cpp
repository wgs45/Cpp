#include <iostream>
using namespace std;

// Template function to sum up two inputs
template <typename T, typename S> S add_2(T input_1, S input_2) {
  return input_1 + input_2;
}

int main() {
  cout << add_2(3.5, 9) << endl;

  return 0;
}
