#include <iostream>
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

template <class T, int Size> class Array {
private:
  T elements[Size];
  int count;

public:
  Array() : count(0) {}

  void add(const T &element) {
    if (count < Size) {
      elements[count] = element;
      count++;
    }
  }

  T &operator[](int index) { return elements[index]; }

  int size() const { return count; }
};

int main() {
  const int MaxSize = 5;
  Array<Person<int>, MaxSize> personArray;

  Person<int> person_1("Alpha", 25);
  Person<int> person_2("Beta", 30);
  Person<int> person_3("Charlie", 35);

  int i;
  for (i = 0; i < personArray.size(); ++i) {
    const Person<int> &person = personArray[i];
    std::cout << "Name: " << person.getName() << ", age: " << person.getAge()
              << std::endl;
  }

  return 0;
}
