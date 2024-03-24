#include <iostream>

int main() {
    int guess = 0, tries = 0;

    std::cout << "Guess a number from 1 to 10: ";
    std::cin >> guess;

    while(guess != 8 && tries < 50) {
        std::cout << "Try again.\n";
        std::cout << "Guess a number from 1 to 10: ";
        std::cin >> guess;
        tries++;

        if (guess == 8) {
            std::cout << "Correct.\n";
            break;
        }
    }

    return 0;
}
