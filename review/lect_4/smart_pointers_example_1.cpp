#include <iostream>
#include <memory>

class MyClass {
    public:
    MyClass() { 
        std::cout << "MyClass is constructed" << std::endl;
    }
    ~MyClass() {
        std::cout << "MyClass is destructed" << std::endl;
    }
};

int main() {
    std::shared_ptr<MyClass> ptr1 (new MyClass());
    std::shared_ptr<MyClass> ptr2 = ptr1;

    // use ptr as needed 
    // both ptr will released the resource when destructed

    return 0;
}
