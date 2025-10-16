#include <iostream>
using namespace std;

class MyClass {
public:
  int data1;
  double data2;

  // Default Constructor
  MyClass() {
    data1 = 0;
    data2 = 0.0;
  }

  MyClass(int d1, double d2) {
    data1 = d1;
    data2 = d2;
  }
};

int main() {
  MyClass obj1;           // Calls the default Constructor
  MyClass obj2(10, 20.5); // Calls the parameterized Constructor

  cout << "Default Constructor: " << obj1.data1 << " " << obj1.data2 << endl;
  cout << "Parameterized Constructor: " << obj2.data1 << " " << obj2.data2
       << endl;

  return 0;
}
