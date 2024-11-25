#include <iostream>
#include <vector>
using namespace std;

// Template class 'MyArray' for generic data type 'T'
template <class T> class MyArray {
private:
  std::vector<T> data; // Internal vector for storage

public:
  // Method to add a value to the array
  // Then push the value into the vector
  void add(T value) { data.push_back(value); }

  // Method to print all elements in the array
  void print() {
    int i;
    for (i = 0; i < data.size(); i++) {
      cout << data[i] << " ";
    }
    cout << endl;
  }
};

// Template specialization for 'char' type
template <> class MyArray<char> {
private:
  std::vector<char> data;

public:
  void add(char value) { data.push_back(value + 1); }

  void print() {
    int i;
    for (i = 0; i < data.size(); i++) {
      cout << data[i] << " ";
    }
  }
};

int main() {
  MyArray<int> array_1;
  array_1.add(5);
  array_1.add(6);
  array_1.print();

  MyArray<char> array_2;
  array_2.add('g');
  array_2.add('o');
  array_2.print();

  cout << endl;

  return 0;
}
