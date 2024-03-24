#include <iostream>

int main() {
    std::cout << "Loops.\n";

    int password = 0, tries = 0;

    std::cout << "Enter password: ";
    std::cin >> password;

    tries++;

    while(password != 1234 && tries < 3) {
        std::cout << "Enter password: ";
        std::cin >> password;
        tries++;

        if (password == 1234) {
            std::cout << "Access granted...";
            break;
        }
    }

    return 0;
}
