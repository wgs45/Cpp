#include <iostream>

int main() {
    double weight_earth = 0, weight_mars = 0, km = 0, miles = 0;

    std::cout << "Enter weight: ";
    std::cin >> weight_earth;

    weight_mars = weight_earth * 3.73 / 9.81;
    std::cout << "The weight in Mars is: " << weight_mars << " kg.\n";

    std::cout << "Enter distance in km: ";
    std::cin >> km;

    miles = km / 1.609;
    std::cout << "The distance in miles: " << miles << " miles.\n";

    return 0;
}
