#include <iostream>
#include <list>
using namespace std;

template <typename T> class Car {
public:
  Car(T p) { pos = p; }
  T pos;
};

template <typename T> void show(std::list<Car<T> *> myList) {
  typename list<Car<T> *>::iterator it;
  for (it = myList.begin(); it != myList.end(); it++) {
    cout << (*it)->pos << endl;
  }
};

int main() {
  Car<double> *a = new Car<double>(1.2);
  Car<double> *b = new Car<double>(2.3);
  Car<double> *c = new Car<double>(3.4);

  std::list<Car<double> *> myList;
  myList.push_back(a);
  myList.push_back(b);
  myList.push_back(c);
  show(myList);

  return 0;
}
