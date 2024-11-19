#include <iostream>
#include <set>
using namespace std;

// The `set` container in C++ automatically stores only unique values

int main() {
  // Initialize an array with some integer values
  int arr[] = {6, 3, 5, 1};

  // Create a set and initialize it with elements from the array
  // Elements are stored in sorted order: {1, 3, 5, 6}
  set<int> se(arr, arr + 4);

  // Attempt to insert the value 3 into the set
  // No effect since 3 is already present (set maintains unique values)
  se.insert(3);

  // Remove the value 5 from the set
  se.erase(5); // Set now contains: {1, 3, 6}

  // Declare an iterator to traverse the set
  set<int>::iterator it;
  it = se.begin(); // Point the iterator to the first element

  // Iterate through the set and print its elements
  while (it != se.end()) {
    cout << *it << " "; // Dereference the iterator to access the value
    it++;               // Move to the next element
  }

  return 0;
}
