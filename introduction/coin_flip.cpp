#include <iostream>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int coin = rand() % 2;

    (coin == 0) ? std::cout << "Heads.\n" : std::cout << "Tails.\n";

    return 0;
}
