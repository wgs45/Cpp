#include <iostream>

int main() {
    int year = 2019, tips = 0;

    year = 2019 * 99;

    std::cout << "My attack power is " << year << "\n";

    std::cout << "Enter the amount of tips: ";
    std::cin >> tips;

    std::cout << "You paid " << tips << " Dollars" << "\n";

    return 0;
}
