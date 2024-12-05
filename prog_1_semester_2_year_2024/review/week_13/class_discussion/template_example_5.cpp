#include <iostream>
using namespace std;

// A generic array class with a fixed size (N) and type (T)
template <class T, size_t N> class Array {
public:
  T elements[N];  // Internal storage for elements of type T
  size_t current; // Tracks the number of elements currently in the array

  Array() { current = 0; }

  // Adds an element to the array if there's availabe space
  void add(const T &element) {
    if (current < N) {
      elements[current] = element; // Store the element
      current++;                   // Increment the count of elements
    }
  }

  // Returns the number of elements currently in the array
  size_t size() const { return current; }

  // Provides a pointer to the internal array (read-only access)
  const T *getElements() const { return elements; }
};

// Generic 'cal' function to calculate the sum of all elements in an array
template <class T, size_t N> T cal(Array<T, N> container) {
  T sum = 0;

  // Access the array elements
  const T *elements = container.getElements();
  for (size_t i = 0; i < container.size(); ++i) {
    sum += elements[i];
  }
  return sum;
}

// Specialized 'cal' function for Array of 'char' type
// Instead of calculating a sum, it prints the elements and their count
template <size_t N> void cal(Array<char, N> container) {
  cout << N << endl; // Print the size of the array (N)
  for (size_t i = 0; i < N; i++) {
    cout << container.elements[i];
  }
}

int main() {
  Array<char, 5> ca;
  ca.add('H');
  ca.add('e');
  ca.add('l');
  ca.add('l');
  ca.add('o');
  cal(ca);

  cout << endl;

  return 0;
}
