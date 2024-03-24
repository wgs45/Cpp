#include <iostream>

int main() {
    int input_year = 0;

    std::cout << "Enter a year: ";
    std::cin >> input_year;

    while(input_year > 0) {
        if (input_year % 4 == 0 || input_year % 400 == 0) {
            std::cout << input_year << " is a leap year.\n";
            break;
        } else if (input_year % 100 == 0){
            std::cout << input_year << " is not a leap year.\n";
            break;
        } else {
            std::cout << input_year << " is not a leap year.\n";
            break;
        }
    } 

    return 0;
}
