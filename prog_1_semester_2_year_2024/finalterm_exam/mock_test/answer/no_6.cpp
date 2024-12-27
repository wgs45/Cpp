#include <iostream>
#include <map>
using namespace std;

// Template class Car to hold position of type T
template <class T> class Car {
public:
  T pos; // Position of the car

  // Constructor to initialize position
  Car(T p) : pos(p) {}

  // Default constructor (needed for insertion in std::map)
  Car() : pos(0) {}
};

// Function to search for a car by its position
// Returns the car ID if found, otherwise returns -1
template <typename T>
int searchCar(const std::map<int, Car<T>> &myMap, T target) {
  for (const auto &pair : myMap) {
    if (pair.second.pos == target) {
      return pair.first; // Return car ID if position matches
    }
  }
  return -1; // Return -1 if not found
}

int main() {
  // Create a map to store cars with their IDs
  std::map<int, Car<double>> myMap;

  // Add 10 Car objects with positions from 0.0 to 9.9
  for (int i = 0; i < 10; ++i) {
    myMap[i] = Car<double>(i * 1.1); // Assign positions as multiples of 1.1
  }

  // Prompt user to enter a target value
  double target;
  cout << "Enter a position to search for: ";
  cin >> target;

  // Search for the car with the given position
  int result = searchCar(myMap, target);

  // Print the result
  if (result == -1) {
    cout << "Car with position " << target << " not found." << endl;
  } else {
    cout << "Car with position " << target << " found. Car ID: " << result
         << endl;
  }

  return 0;
}
