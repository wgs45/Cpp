#include <iostream>
#include <list>
using namespace std;

void show(list<int> &ll) {
  list<int>::iterator t; // Iterator to traverse the list

  // Iterate from the beginning to the end of the list
  for (t = ll.begin(); t != ll.end(); t++) {
    cout << *t << " "; // Print the value pointed by the iterator
  }
}

int main() {
  int arr[] = {5, 6, 7, 3, 2};

  // Create a list and initialize it with elements from the array
  list<int> my_list(arr, arr + 5);

  // Declare an iterator to manipulate the list
  list<int>::iterator it;

  // Point the iterator to the beginning of the list
  it = my_list.begin();

  // Move the iterator to the 3rd element (0-based index: 2)
  advance(it, 2);

  // Insert 99 before the 3rd element in the list
  my_list.insert(it, 99);

  // Remove all occurrences of the value 7 from the list
  my_list.remove(7);

  show(my_list);

  return 0;
}
