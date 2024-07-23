#include <iostream>
using namespace std;

class Line {
public:
  void set_length(double len);
  double get_length(void);
  Line(); // Constructor

private:
  double length;
};

Line::Line(void) { cout << "Object is being created" << endl; }

void Line::set_length(double len) { length = len; }

double Line::get_length(void) { return length; }

int main() {
  Line l;
  l.set_length(6.0);
  cout << "Length of line: " << l.get_length() << endl;

  return 0;
}
