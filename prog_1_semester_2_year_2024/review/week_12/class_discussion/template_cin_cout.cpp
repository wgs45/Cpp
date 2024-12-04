#include <iostream>
using namespace std;

template <class T> class MyObject {
public:
  MyObject(T value_) : value(value_) {}

private:
  T value;
  friend ostream &operator<<(ostream &os, const MyObject<T> &obj) {
    os << obj.value << endl;
    return os;
  }
};

int main() {
  MyObject<int> obj_1(2);
  cout << obj_1;
  cout << MyObject<int>(3) << endl;

  return 0;
}
