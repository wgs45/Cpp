#include <iostream>
#include <map>
using namespace std;

// Template class Car to hold position of type T
template <class T> class Car {
public:
  Car(T p) { pos = p; } // Constructor to initialize position
  T pos;                // Position of the car
};

// Function to display the map contents
template <typename T> void show(std::map<int, Car<T> *> myMap) {
  typename map<int, Car<T> *>::iterator it;

  for (it = myMap.begin(); it != myMap.end(); ++it) {
    cout << "Car ID: " << it->first << endl;             // Display car ID
    cout << "Car Position: " << it->second->pos << endl; // Display car position
    cout << endl;
  }
}

// Function to find a car by its position
// Returns the car ID if found, otherwise returns -1
template <typename T> int find(map<int, Car<T> *> myMap, T target) {
  typename map<int, Car<T> *>::iterator it;

  for (it = myMap.begin(); it != myMap.end(); ++it) {
    if (it->second->pos == target) {
      return it->first; // Return car ID if position matches
    }
  }
  return -1; // Return -1 if not found
}

int main() {
  // Create Car objects with positions
  Car<double> *a = new Car<double>(1.2);
  Car<double> *b = new Car<double>(2.3);
  Car<double> *c = new Car<double>(3.5);

  // Create a map to store cars with their IDs
  std::map<int, Car<double> *> myMap;
  myMap.insert(std::make_pair(1, a));
  myMap.insert(std::make_pair(2, b));
  myMap.insert(std::make_pair(3, c));

  // Find a car with position 3.5
  cout << "Target found: " << find(myMap, 3.5) << endl;

  // Display all cars in the map
  show(myMap);

  // Clean up dynamically allocated memory
  for (std::map<int, Car<double> *>::iterator it = myMap.begin();
       it != myMap.end(); ++it) {
    delete it->second;
  }

  return 0;
}
