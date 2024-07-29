#include <iostream>
#include <string.h>
using namespace std;

class Example {
  string *ptr;

public:
  // constructors:
  Example() : ptr(new string) {}
  Example(const string &str) : ptr(new string(str)) {}
  // destructor:
  // simce we dynamically allocate string
  ~Example() { delete ptr; }
  // access content:
  const string &content() const { return *ptr; }
};

int main() {
  Example foo;
  Example bar("TKU CSIE is the best!");
  cout << "Bar's content: " << bar.content() << endl;

  return 0;
}
