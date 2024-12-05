#include <iostream>
using namespace std;

// A generic array with a fixed size (N) and type (T)
template <class T, size_t N> class Array {
  T elements[N];      // Internal storage for elemnts of type T
  size_t current = 0; // Tracks the number of elements added

public:
  // Adds on element to the arrat if there's space
  void add(const T &element) {
    if (current < N) {
      elements[current++] =
          element; // Store the element and increment the counter
    }
  }

  // Returns the number of elements currently in the array
  size_t size() const { return current; }

  // provides access to the internal array of elements (read-only)
  const T *getElements() const { return elements; }
};

// A function template to calculate the sum of all elements in the container
template <class T, size_t N> T cal(const Array<T, N> &container) {
  T sum = 0;

  // Gett the array of elements
  const T *elements = container.getElements();
  for (size_t i = 0; i < container.size(); ++i) {
    sum += elements[i]; // Add each elememnt to the sum
  }
  return sum;
}

// A function template to display the sum of elements in the container
template <class T, size_t N> void display(const Array<T, N> &container) {
  T sum = cal(container); // To compute the sum
  cout << sum << endl;
}

int main() {
  Array<float, 5> floatadd;
  floatadd.add(1.5);
  floatadd.add(2.5);
  floatadd.add(3.5);
  floatadd.add(4.5);
  floatadd.add(5.5);
  display(floatadd);

  Array<int, 5> intadd;
  intadd.add(3);
  intadd.add(4);
  intadd.add(5);
  intadd.add(6);
  intadd.add(7);
  display(intadd);

  Array<double, 5> doubleadd;
  doubleadd.add(33.5);
  doubleadd.add(44.6);
  doubleadd.add(55.7);
  doubleadd.add(66.8);
  doubleadd.add(77.9);
  display(doubleadd);
}
