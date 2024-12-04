#include <iostream>
#include <string>

// Template class reperesent person name and age
template <class T> class Person {
private:
  std::string name;
  T age;

public:
  Person() {} // Default constructor
  Person(const std::string &name, const T &age)
      : name(name), age(age) {
  } // Parameterized constructor to initialized value

  // Getter function
  std::string getName() const { return name; }
  T getAge() const { return age; }
};

// Template class for a fixed-sized array of elements of type T
template <class T, int Size> class Array {
private:
  T elements[Size]; // Fixed array size to store elements
  int count;

public:
  Array() : count(0) {} // Initialized constructor

  void add(const T &element) {
    if (count < Size) {
      elements[count] = element;
      count++;
    }
  }

  // Overload subscript operator to access elements by index
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
    std::cout << "Name: " << person.getName() << ", Age: " << person.getAge()
              << std::endl;
  }

  return 0;
}
