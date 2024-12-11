#include <iostream>
using namespace std;

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
  MyObj<int> *obj_1 = new MyObj<int>(10);
  MyObj<int> *obj_2 = new MyObj<int>(20);
  MyObj<int> *obj_3 = new MyObj<int>(30);

  obj_1->next = obj_2;
  obj_2->next = obj_3;

  cout << "Start -> ";
  MyObj<int> *current = obj_1;
  while (current != NULL) {
    cout << current->data << " -> ";
    current = current->next;
  }

  cout << "NULL ";
  cout << endl;

  return 0;
}
