#include <iostream>

class Test {
    static int x;
    public:
        static int y;
        void func(int x) {
        std::cout << "Value of static x is " << Test::x;
        std::cout << "\nValue of static y is " << x;
    }

};

// static members must be explicitly defined
int Test::x = 1;
int Test::y = 2;

int main() {
    Test obj;
    int x = 3;
    obj.func(x);

    std::cout << "\nTest::y = " << Test::y;

    return 0;
}
