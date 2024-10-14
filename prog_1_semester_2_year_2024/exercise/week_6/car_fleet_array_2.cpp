#include <iostream>
using namespace std;

// Car fleet design array new: dynamically allocate the object array

class Car {
private:
  int x, y;

public:
  Car() : x(0), y(0) {} // Default constructor
  Car(int x_coordinate, int y_coordinate)
      : x(x_coordinate), y(y_coordinate) {} // Parameterized constructor

  // Declare Show() as a friend to access private members
  friend void Show(Car *fleet, int size);
};

void Show(Car *fleet, int size) {
  for (int i = 0; i < size; i++) {
    cout << "Car " << i + 1 << ": (" << fleet[i].x << ", " << fleet[i].y << ")"
         << endl;
  }
}

int main() {
  int size = 3;

  // Dynamically allocate the array
  Car *fleet = new Car[size];

  // Initialize each car
  fleet[0] = Car(1, 2);
  fleet[1] = Car(3, 4);
  fleet[2] = Car(5, 6); // Show the fleet
  Show(fleet, size);

  // Free allocated memory
  delete[] fleet;

  return 0;
}
