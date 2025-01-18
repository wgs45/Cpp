#include <iostream>
using namespace std;

class Car {
public:
    int x;
    Car() { x = 6; }
};

int main() {
    Car c;

    cout << "Result: " << c.x << endl;
 
    return 0;
}
