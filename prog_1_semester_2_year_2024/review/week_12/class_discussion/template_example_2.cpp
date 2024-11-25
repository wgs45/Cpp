#include <iostream>
#include <list>
using namespace std;

class Person {
public:
  int ID;

  // Constructor to initalize the id
  Person(int id) { ID = id; }

  // Default Constructor
  Person() {}
};

// Template class to create a custom list for any type 'T'
template <class T> class List {
public:
  list<T> elements; // A standard library 'list' container to hold elements

  // Method to add an element to the list
  void add(T p) { elements.push_back(p); }

  // Method to get an iterator pointing to the beginning of the list
  typename list<T>::iterator begin() { return elements.begin(); }

  // Method to get an iterator pointing to the end of the list
  typename list<T>::iterator end() { return elements.end(); }
};

int main() {
  // Create two person object with a different ID
  Person p1(160);
  Person p2(170);

  // Create a custom list to store 'Person' objects
  List<Person> a;
  a.add(p1);
  a.add(p2);

  // Use an iterator to traverse the custom list
  list<Person>::iterator it;
  for (it = a.begin(); it != a.end(); it++) {
    const Person &pp = *it; // Dereference the iterator to get the 'Person'
    cout << pp.ID << " -> ";
  }
  cout << "NULL"; // Indicate the end of the list
  cout << endl;

  return 0;
}
