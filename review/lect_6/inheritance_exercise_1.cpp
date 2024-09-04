#include <iostream>
using namespace std;

class A {
public:
  int x = 0;
  int get_pvt() { return z; } // Accessor for private member of z

protected:
  int y = 1;

private:
  int z = 2;
};

class B : public A {
  // x is public
  // y is protected
  // z is not accessible from B
public:
  // Public access to y, since y is protected in A
  int getY() { return y; }

  // Public access to z through get_pvt()
  int getZ() { return get_pvt(); }
};

class C : protected A {
  // x is protected
  // y is protected
  // z is not accessible from C
public:
  // Public access to x, since x is protected in C
  int getX() { return x; }

  // Public access to y, since y is protected in C
  int getY() { return y; }

  // Public access to z through get_pvt()
  int getZ() { return get_pvt(); }
};

class D : private A {
  // 'private' is default for classes
  // x is private
  // y is private
  // z is not accessible from D
public:
  // Public access to x, since x is private in D
  int getX() { return x; }

  // Public access to y, since y is private in D
  int getY() { return y; }

  // Public access to z through get_pvt()
  int getZ() { return get_pvt(); }
};

int main() {
  B obj1;
  C obj2;
  D obj3;

  // Access x, y and z through apropriate member func
  cout << "B -> x: " << obj1.x << ", y: " << obj1.getY()
       << ", z: " << obj1.getZ() << endl;
  cout << "C -> x: " << obj2.getX() << ", y: " << obj2.getY()
       << ", z: " << obj2.getZ() << endl;

  cout << "D -> x: " << obj3.getX() << ", y: " << obj3.getY()
       << ", z: " << obj3.getZ() << endl;

  return 0;
}
