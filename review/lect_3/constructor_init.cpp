#include <iostream>
using namespace std;

class Line {
public:
    void set_length(double len);
    double get_length(void);
    Line() = default;
    Line(double len): length(len) {};
private:
    double length;
};

void Line::set_length(double len) {
    length = len;
}

double Line::get_length(void) {
    return length;
}

int main() {
    Line line1, line2(10.0);
    cout << "Length of line1: " << line1.get_length() << endl;
    cout << "Length of line2: " << line2.get_length() << endl;
    line1.set_length(6.0);
    cout << "Length of line1: " << line1.get_length() << endl;

    return 0;
}
