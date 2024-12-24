#include <iostream>
#include <map>
using namespace std;

template <class T> class Car {
public:
  Car(T p) { pos = p; }
  T pos;
};

template <typename T> void show(std::map<int, Car<T> *> myMap) {
  typename map<int, Car<T> *>::iterator it;

  for (it = myMap.begin(); it != myMap.end(); it++) {
    cout << (*it).first << endl;
    cout << (*((*it).second)).pos << endl;
    cout << endl;
  }
}

template <typename T> int find(map<int, Car<T> *> myMap, T target) {
  typename map<int, Car<T> *>::iterator it;

  for (it = myMap.begin(); it != myMap.end(); it++) {
    if ((*(*it).second).pos == target) {
      return (*it).first;
    }
  }
  return -1;
}

int main() {
  Car<double> *a = new Car<double>(1.2);
  Car<double> *b = new Car<double>(2.3);
  Car<double> *c = new Car<double>(3.5);

  std::map<int, Car<double> *> myMap;
  myMap.insert({1, a});
  myMap.insert({2, b});
  myMap.insert({3, c});
  cout << "Target found: " << find(myMap, 3.5) << endl;

  show(myMap);

  return 0;
}
