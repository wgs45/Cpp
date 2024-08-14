#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass() {
        std::cout << "MyClass Constructor" << std::endl;
    }
    ~MyClass() {
        std::cout << "MyClass Destructor" << std::endl;
    }
    void display() {
        std::cout << "Hello from MyClass!" << std::endl;
    }
};

int main() {
    // Create another shared pointer that shares ownership with ptr1
    std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>();

    // Use the object 
    ptr1 -> display();

    {
        // create another shared_ptr that shares ownership with ptr1 
        std::shared_ptr<MyClass> ptr2 = ptr1;
        
        // now both ptr1 and ptr2 points to the same object
        std::cout << "Use count (inside block): " << ptr1.use_count() << std::endl;

        // use object through ptr2
        ptr2 -> display();
    } // ptr2 goes out of scope here and is automatically destroyed 

    // ptr1 is still valid, and the object is still alive
    std::cout << "Use count (after block): " << ptr1.use_count() << std::endl;

    // when main ends, ptr1 is destroyed and the object is automatically deleted

    return 0;
}
