#include <iostream>
using namespace std;

// Car fleet design array without new: declaring an object array

class Car {
private:
  int x, y;

public:
  Car() : x(0), y(0) {} // Default constructor
  Car(int x_coordinate, int y_coordinate)
      : x(x_coordinate), y(y_coordinate) {} // Parameterized constructor

  // Declare Show() as friend to access private members
  friend void Show(Car fleet[], int size);
};

// Define the Show function to access the fleet array and display coordinates
void Show(Car fleet[], int size) {
  int i = 0;
  for (i = 0; i < size; i++) {
    cout << "Car" << i + 1 << ": (" << fleet[i].x << ", " << fleet[i].y << ")"
         << endl;
  }
}

int main() {
  Car fleet[3] = {Car(1, 2), Car(3, 4), Car(5, 6)};

  Show(fleet, 3);

  return 0;
}
