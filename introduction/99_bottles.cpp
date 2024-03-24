#include <iostream>

int main() {
    int i;

    for (i = 99; i > 0; i--) {
        std::cout << i << " bottles of pop in the wall.\n";
        std::cout << "Take one down and pass it.\n";
        std::cout << i - 1 << " bottles of pop in the wall.\n\n";
    }

    return 0;
}
