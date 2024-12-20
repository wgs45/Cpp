#include <iostream>
using namespace std;

template <typename T, typename S>
auto add(T input_1, S input_2) -> decltype(input_1 + input_2) {
  return input_1 + input_2;
}

int main() {
  cout << add(1, 2) << endl;
  cout << add(1.1, 2.2) << endl;
  cout << add(5.2, 3.1) << endl;
  cout << add(4.1, 3.2) << endl;

  return 0;
}
