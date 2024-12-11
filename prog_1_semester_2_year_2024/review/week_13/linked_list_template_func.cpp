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

template <typename T> void show_list(MyObj<T> *head) {

  cout << "START -> ";
  MyObj<T> *current = head;
  while (current != NULL) {
    cout << current->data << " -> ";
    current = current->next;
  }

  cout << " NULL ";
}

int main() {

  // ´ÿ•ﬂ≥sµ≤¶Í¶C
  MyObj<int> *obj1 = new MyObj<int>(10);
  MyObj<int> *obj2 = new MyObj<int>(20);
  MyObj<int> *obj3 = new MyObj<int>(30);

  obj1->next = obj2;
  obj2->next = obj3;

  cout << "START -> ";
  MyObj<int> *current = obj1;
  while (current != NULL) {
    cout << current->data << " -> ";
    current = current->next;
  }

  cout << " NULL ";
  cout << endl;

  return 0;
}
