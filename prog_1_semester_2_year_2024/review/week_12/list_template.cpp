#include <iostream>
#include <list>
using namespace std;

template <class T> class List {
public:
  std::list<T> elements;

  void add(const T &element) { elements.push_back(element); }

  typename std::list<T>::iterator begin() { return elements.begin(); }

  typename std::list<T>::iterator end() { return elements.end(); }
};

int main() {
  List<int> a;
  a.add(6);
  a.add(5);

  std::list<int>::iterator it;
  for (it = a.begin(); it != a.end(); ++it) {
    cout << *it << " ";
  }

  return 0;
}
