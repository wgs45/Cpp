#include <iostream>
#include <memory>

int main() {
    // object to which pointer p points has one user
    auto p = std::make_shared<int>(42);
    auto q(p); // p and q points to the same object 
    // q is the copy of p 
    // object to which p and q point has two users 

    // int to which r points has one user 
    auto r = std::make_shared<int>(42);
    r = q; // assign to r, it points to a different
    // address 

    // additional info:
    // increase use count for the object to which q 
    // points
    // reduce use count for the object to which r 
    // points
    // the object r has pointed to zero user, 
    // therefore the object is automatically freed

    std::cout << r.unique() << std::endl;
    std::cout << r.use_count() << std::endl;

    return 0;
}
