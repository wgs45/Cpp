// hw 9 default answer (simple and straightforward answer)
#include <iostream>
using namespace std;

int add(int a, int b) { return a + b; }

float add(float a, int b) { return a + b; }

float add(int a, float b) { return a + b; }

float add(float a, float b) { return a + b; }

int main() {
  int a = 10, b = 5;
  float c = 3.5, d = 4.5;

  cout << add(a, b) << endl;
  cout << add(a, c) << endl;
  cout << add(c, a) << endl;
  cout << add(c, d) << endl;

  return 0;
}
