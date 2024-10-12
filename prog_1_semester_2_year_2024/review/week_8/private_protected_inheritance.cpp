#include <iostream>
using namespace std;

class Base {
private:
  int a;

protected:
  int b;

public:
  int c;
};

class D1 : public Base {
public:
  D1() {
    // a = 0; // Base is private -> cannot access
    b = 0; // Base is protected -> here also protected
    c = 0; // Base is public -> here also public
  }
};

class DD1 : public D1 {
public:
  DD1() {
    b = 0; // Can access, because b in D2 is protected
    c = 0; // Can access, because c in D2 is public
  }
};

class D2 : protected Base {
public:
  D2() {
    // a = 0; // Base is private -> cannot access
    b = 0; // Base is protected -> here becomes protected
    c = 0; // Base is protected -> here becomes protected
  }
};

class DD2 : public D2 {
public:
  DD2() {
    b = 0; // Can access, because b in D2 is protected
    c = 0; // Can access, because c in D2 is protected
  }
};

class D3 : private Base {
public:
  D3() {
    // a = 0; // base is private -> cannot access
    b = 0; // base is protected -> here becomes private
    c = 0; // base is protected -> her becomes private
  }
};

class DD3 : public D3 {
public:
  DD3() {
    // b = 0; // Cannot access, because b in D3 becomes private
    // c = 0; // Cannot access, because c in D3 becomes private
  }
};

int main() {
  D1 d1;
  d1.c = 3; // Can access, because c here is public

  D2 d2;
  // d2.c = 3; // Cannot access, c here becomes protected

  DD2 dd2;
  // dd2.c = 3; // Cannot access, c here is protected since D2

  D3 d3;
  // d3.c = 3; // Cannot access, c here becomes private

  DD3 dd3;
  // dd3.c = 3; // Cannot access, c here is protected since D3

  return 0;
}
