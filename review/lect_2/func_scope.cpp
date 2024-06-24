#include <iostream>
int global = 5;

int main() {
    std::cout << "Global variable: " << global << std::endl;

    int global = 2;
    std::cout << "Local variable: " << global << std::endl;

    return 0;
}
