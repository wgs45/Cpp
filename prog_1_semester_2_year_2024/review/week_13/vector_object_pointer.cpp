#include <iostream>
#include <vector>
using namespace std;

template <class T> class ObjectVector {
public:
  std::vector<T *> objects;
  void addObj(T *obj) { objects.push_back(obj); }
};

class MyObj {
public:
  int data;
  MyObj *next;
  MyObj(const int &value) {
    data = value;
    next = NULL;
  }
};

int main() {
  ObjectVector<MyObj> vec;

  MyObj *obj_1 = new MyObj(10);
  MyObj *obj_2 = new MyObj(20);
  MyObj *obj_3 = new MyObj(30);

  vec.addObj(obj_1);
  vec.addObj(obj_2);
  vec.addObj(obj_3);

  int i;
  for (i = 0; i < vec.objects.size(); i++) {
    cout << vec.objects[i]->data << " ";
  }

  cout << endl;

  return 0;
}
