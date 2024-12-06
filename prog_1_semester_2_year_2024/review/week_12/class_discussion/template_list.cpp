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

  typename std::list<T>::iterator end() { return my_list.end(); }
};

int main() {
  List<Person<int>> personList;
  Person<int> person_1("Alpha", 25);
  Person<int> person_2("Beta", 30);
  Person<int> person_3("Charlie", 35);

  personList.add(person_1);
  personList.add(person_2);
  personList.add(person_3);

  std::list<Person<int>>::iterator it;
  for (it = personList.begin(); it != personList.end(); it++) {
    std::cout << (*it).getName() << ", " << (*it).getAge() << std::endl;
  }

  return 0;
}
