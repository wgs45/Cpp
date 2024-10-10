#include <iostream>
using namespace std;

class Student {
  string name;
  int age;

public:
  Student() { cout << "Constructor is called" << endl; }

  Student(string name, int age) {
    this->name = name;
    this->age = age;
  }

  void display() {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
  }

  void *operator new(size_t size) {
    cout << "Overloading new operator with size: " << size << endl;
    void *p = ::operator new(size);
    // void *p = malloc(size); // this is another fine method

    return p;
  }

  void operator delete(void *p) {
    cout << "Overloading delete operator" << endl;
    free(p);
  }
};

int main() {
  Student *p = new Student("Alpha", 44);

  p->display();
  delete p;

  return 0;
}
