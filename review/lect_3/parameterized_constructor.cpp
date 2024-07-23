#include <iostream>
using namespace std;

class Line {
public:
    void set_length(double len);
    double get_length( void );
    Line(double len); // constructor with parameter
private:
    double length;
};

Line::Line(double len) {
    cout << "Object is being created, " << "length: " << len << endl;
}

void Line::set_length(double len) {
    length = len;
}

double Line::get_length(void) {
    return length;
}

int main() {
    Line line(10.0);
    
    cout << "Length of line: " << line.get_length()<< endl;
    line.set_length(6.0);
    cout << "Length of line: " << line.get_length()<< endl;

    return 0;
}
