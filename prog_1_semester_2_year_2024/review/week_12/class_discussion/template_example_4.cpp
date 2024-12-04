#include <iostream>
#include <list>
#include <string>

template <class T> class Person {
private:
  std::string name;
  T age;

public:
  Person() {}
  Person(const std::string &name, const T &age) : name(name), age(age) {}
  std::string getName() const { return name; }
  T getAge() const { return age; }
};

template <class T> class List {
private:
  std::list<T> my_list;

public:
  void add(const T &element) { my_list.push_back(element); }

  typename std::list<T>::iterator begin() { return my_list.begin(); }
};

int main() {
  int i;

  return 0;
}
