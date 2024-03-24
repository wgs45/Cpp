#include <iostream>

int main() {
    int i = 0, square = 0;

    while(i < 10) {
        square = i * i;

        std::cout << i << " " << square << "\n";
        i++;
    }

    return 0;
}
