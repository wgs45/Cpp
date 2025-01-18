#include <iostream>
using namespace std;

class Car {
private:
    friend void Display(Car &);
    int x, y;

public:
    Car() {
        x = 0;
        y = 0;
    }

    Car(int x, int y) {
        this -> x = x;
        this -> y = y;
    }
};

void Display(Car &c) {
    cout << "Result: " << c.x << ", " << c.y << endl;
};

int main() {
    Car car1[3];
    Car *car2 = new Car();

    int i;
    for (i = 0; i < 3; i++) {
        car1[i] = Car(i * 2, i * 3);
        car2[i] = Car(i * 4, i * 5);
    }

    for (i = 0; i < 3; i++) {
        Display(car1[i]);
        Display(car2[i]);
    }
    
    return 0;
}
