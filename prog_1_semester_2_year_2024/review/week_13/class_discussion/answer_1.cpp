#include <iostream>
#include <vector>
using namespace std;

template <class U> class Car {
public:
  U pos;
  Car(U p) { pos = p; }
};

template <class T> void show(vector<T *> v) {
  int i;
  for (i = 0; i < v.size(); i++) {
    cout << v[i]->pos << endl;
  }
}

int main() {
  vector<Car<double> *> vec;

  Car<double> *a = new Car<double>(1.2);
  Car<double> *b = new Car<double>(2.3);
  Car<double> *c = new Car<double>(3.5);

  vec.push_back(a);
  vec.push_back(b);
  vec.push_back(c);
  show(vec);

  return 0;
}
