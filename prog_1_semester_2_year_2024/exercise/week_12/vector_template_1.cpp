#include <iostream>
#include <vector>
using namespace std;

// Template class 'my_array' to manage a collection of any type 'T'
template <class T> class MyArray {
private:
  std::vector<T> data; // Internal storage using 'std::vector'

public:
  void add(T value); // Method to add value to the array
  void print();      // Method to print all elements in the array
};

// Implementation of the 'add' Method
// Adds the provided value to the internal vector
template <class T> void MyArray<T>::add(T value) { data.push_back(value); }

// Implementation of the 'print' Method
// Iterates over the elements in the vector and prints each one
template <class T> void MyArray<T>::print() {
  int i;
  for (i = 0; i < data.size(); i++) {
    cout << data[i] << endl;
  }
}

int main() {
  // Create an instances of 'my_array' specialized for 'int'
  MyArray<int> array;
  array.add(1);
  array.add(2);
  array.print();

  return 0;
}
