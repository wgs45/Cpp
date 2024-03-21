#include <iostream>

int main() {
    double tempf = 0, tempc = 0;

    std::cout << "Enter a faranheit: ";
    std::cin >> tempf;

    tempc = (tempf - 32) / 1.8;
    std::cout << "The temp is " << tempc << " degrees Celcius.\n";

    return 0;
}
