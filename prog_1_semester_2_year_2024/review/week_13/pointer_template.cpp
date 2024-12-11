#include <iostream>
using namespace std;

template <class T> class MyObj {
public:
  T data;
  MyObj(const T &value) { data = value; }
};

int main() {
  MyObj<int> *obj_1 = new MyObj<int>(10);
  cout << obj_1->data << endl;
  delete obj_1;

  MyObj<double> *obj_2 = new MyObj<double>(3.14);
  cout << obj_2->data << endl;
  delete obj_2;

  MyObj<std::string> *obj_3 = new MyObj<std::string>("Hello");
  cout << obj_3->data << endl;
  delete obj_3;

  return 0;
}
