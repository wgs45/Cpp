#include <iostream>
#include <string>
using namespace std;

class Example {
  string *ptr;

public:
  // constructor:
  Example() : ptr(new string) {}
  Example(const string &str) : ptr(new string(str)) {}
};

int main() {
  int i = 0;

  return 0;
}
