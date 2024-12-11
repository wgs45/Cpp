#include <iostream>
#include <list>
using namespace std;

class Person {
public:
  int ID;
  Person(int id) { ID = id; }
  Person() {}
};

template <class T> class List {
public:
  std::list<T> elements;

  void add(const T &e) { elements.push_back(e); }
  typename std::list<T>::iterator begin() { return elements.begin(); }

  typename std::list<T>::iterator end() { return elements.end(); }
};

int main() {
  Person p1(160);
  Person p2(170);
  List<Person> a;

  a.add(p1);
  a.add(p2);

  std::list<Person>::iterator it;
  for (it = a.begin(); it != a.end(); it++) {
    const Person &pp = *it;
    cout << pp.ID << endl;
  }

  return 0;
}
