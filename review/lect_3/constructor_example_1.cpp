#include <iostream>
#include <string>
using namespace std;

class Example {
    string *ptr;
public:
    // constructor:
    Example(): ptr(new string) {}
    Example(const string& str): ptr(new string(str)) {}
    // destructor:
    // since we dynamically allocate a string 
    ~Example() {delete ptr;}
    // access content:
    const string& content() const {return *ptr;}
};

int main() {
    Example foo;
    Example bar("C++ is the best!");
    cout << "Bar's content: " << bar.content() << endl;

    return 0;
}
