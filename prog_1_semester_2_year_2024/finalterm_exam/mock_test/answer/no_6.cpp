#include <iostream>
#include <map>
using namespace std;

// Template class Car
template <typename T> class Car {
public:
  T pos;

  Car(T position = T()) : pos(position) {}
};

// Function to search for a car in the map
template <typename T>
int searchCar(const map<int, Car<T>> &carMap, T targetPos) {
  for (const auto &pair : carMap) {
    if (pair.second.pos == targetPos) {
      return pair.first; // Return the key if found
    }
  }
  return -1; // Return -1 if not found
}

int main() {
  map<int, Car<double>> carMap;

  for (int i = 0; i < 10; ++i) {
    carMap[i] = Car<double>(i * 1.1); // Set pos to 0.0, 1.1, 2.2, ...
  }

  // Input target
  cout << "Enter the target position to search: ";
  double targetPos;
  cin >> targetPos;

  // Search function
  int result = searchCar(carMap, targetPos);

  // Output
  if (result != -1) {
    cout << "Car found at key: " << result << endl;
  } else {
    cout << "Car with position " << targetPos << " not found." << endl;
  }

  return 0;
}