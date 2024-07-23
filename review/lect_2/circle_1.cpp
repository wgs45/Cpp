#include <iostream>

class Circle {
    private:
        double radius; // data members
    public:
        void setRadius(double r);
        double getArea(); // member functions
};

void Circle::setRadius(double r) {
    radius = r;
}

double Circle::getArea() {
    return 3.14 * radius * radius;
}

int main() {
    Circle c1; // object class of Circle
    c1.setRadius(2.5); // call member function to initiate radius

    std::cout << c1.getArea();

    return 0;
}
