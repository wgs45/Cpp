#include <iostream>
using namespace std;

namespace first {
    int val = 500;
}

int main() {
    int val = 300;

    // this var can be accessed outside namespace 
    cout << first::val << endl;

    return 0;
}
