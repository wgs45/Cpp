#include <iostream>
#include <string>
using namespace std;

template <typename T> class Calculator {
public:
  T add(T a, T b) { return a + b; }

  T multiply(T a, T b) { return a * b; }
};

// Template specialization for Calculator when T is string
template <> class Calculator<string> {
public:
  // Concatenate string with space
  string add(string a, string b) { return a + " " + b; }

  // Repeating string
  string multiply(string a, int b) {
    string result = "";
    int i;
    for (i = 0; i < b; ++i) {
      result += a;
    }
    return result;
  }
};

int main() {
  Calculator<int> intCalc;
  int a = 3, b = 5;

  cout << "For integers " << a << " and " << b << ": \n";
  cout << "Sum: " << intCalc.add(a, b) << endl;
  cout << "Product: " << intCalc.multiply(a, b) << endl;

  Calculator<string> stringCalc;
  string str_1 = "Hello", str_2 = "World";
  int repeatCount = 3;

  cout << "For strings " << str_1 << " and " << str_2 << ": \n";
  cout << "Concatenate: " << stringCalc.add(str_1, str_2) << endl;
  cout << "Repeated string: " << stringCalc.multiply(str_1, repeatCount)
       << endl;

  return 0;
}
