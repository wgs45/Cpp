#include <iostream>
using namespace std;

class Car {
private:
    int x;

public:
    Car() { x = 6; }
    void show() { cout << "Result: " << x << endl; }
};

int main() {
    Car c;

    c.show();
 
    return 0;
}
