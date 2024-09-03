#include <iostream>
using namespace std;

// Base class
class Base {
private:
  int pvt = 1; // Private member variable

protected:
  int prot = 2; // Protected member variable

public:
  int pub = 3; // Public member variable

  // Public member function to access the private member 'pvt'
  int getPvt() { return pvt; }
};

// Publicly derived class
class PublicDerived : public Base {
public:
  // Function to access protected member 'prot' from Base
  int getProt() { return prot; }
};

// Protectedly derived class
class ProtectedDerived : public Base {
public:
  // Function to access protected member 'prot' from Base
  int getProt() { return prot; }

  // Function to access public member 'pub' from Base
  int getPub() { return pub; }
};

// Privately derived class
class PrivateDerived : private Base {
public:
  // Function to access protected member 'prot' from Base
  int getProt() { return prot; }

  // Function to access public member 'pub' from Base
  int getPub() { return pub; }
};

int main() {
  // Creating objects of the derived classes
  PublicDerived obj_1;
  ProtectedDerived obj_2;
  PrivateDerived obj_3;

  // Accessing members through the derived class 'PublicDerived'
  cout << "[Output] Object 1: " << endl;
  cout << "Private: " << obj_1.getPvt()
       << endl; // Accessing private member through public function in Base
  cout << "Protected: " << obj_1.getProt()
       << endl; // Accessing protected member through public function in
                // PublicDerived
  cout << "Public: " << obj_1.pub
       << endl; // Direct access to public member in Base
  cout << endl;

  // Accessing members through the derived class 'ProtectedDerived'
  cout << "[Output] Object 2: " << endl;
  cout << "Protected: " << obj_2.getProt()
       << endl; // Accessing protected member through public function in
                // ProtectedDerived
  cout << "Public: " << obj_2.getPub()
       << endl; // Accessing public member through public function in
                // ProtectedDerived
  cout << endl;

  // Accessing members through the derived class 'PrivateDerived'
  cout << "[Output] Object 3: " << endl;
  cout << "Protected: " << obj_3.getProt()
       << endl; // Accessing protected member through public function in
                // PrivateDerived
  cout << "Public: " << obj_3.getPub()
       << endl; // Accessing public member through public function in
                // PrivateDerived

  return 0;
}
