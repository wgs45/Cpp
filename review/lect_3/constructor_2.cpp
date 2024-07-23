#include <iostream>
using namespace std;

class Line {
public:
  void set_length(double len);
  double get_length(void);
  Line() = default; // synthesized default constructor
private:
  double length;
};

void Line::set_length(double len) { length = len; }

double Line::get_length(void) { return length; }

int main() {
  Line line;
  line.set_length(6.0); // set line length
  cout << "Length of line: " << line.get_length() << endl;

  return 0;
}
