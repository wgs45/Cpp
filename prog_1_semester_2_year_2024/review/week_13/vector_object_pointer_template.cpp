#include <iostream>
#include <vector>
using namespace std;

template <class T> class ObjVector {
public:
  std::vector<T *> objects;
  void addObj(T *obj) { objects.push_back(obj); }
};

template <class T> class MyObj {
public:
  T data;
  MyObj *next;
  MyObj(const T &value) {
    data = value;
    next = NULL;
  }
};

int main() {
  ObjVector<MyObj<int>> vec;

  MyObj<int> *obj_1 = new MyObj<int>(10);
  MyObj<int> *obj_2 = new MyObj<int>(20);
  MyObj<int> *obj_3 = new MyObj<int>(30);

  vec.addObj(obj_1);
  vec.addObj(obj_2);
  vec.addObj(obj_3);

  int i;
  for (i = 0; i < vec.objects.size(); i++) {
    cout << vec.objects[i]->data << " ";
  }

  return 0;
}
