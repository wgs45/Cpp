#include <iostream>
#include <map>
#include <memory> // std::shared_ptr

template <typename T> class Car {
public:
  T pos;

  Car(T position) : pos(position) {}
};

// Function to display position
template <typename T>
void show(const std::map<int, std::shared_ptr<Car<T>>> &cars) {
  for (const auto &[id, car] : cars) {
    std::cout << "Car ID: " << id << ", Position: " << car->pos << std::endl;
  }
}

// Function to find a car by position
template <typename T>
int find(const std::map<int, std::shared_ptr<Car<T>>> &cars, T position) {
  for (const auto &[id, car] : cars) {
    if (car->pos == position) {
      return id;
    }
  }
  return -1;
}

int main() {
  auto car_1 = std::make_shared<Car<double>>(1.2);
  auto car_2 = std::make_shared<Car<double>>(2.3);
  auto car_3 = std::make_shared<Car<double>>(3.5);

  // Store car object pointers in std::map with IDs as keys
  std::map<int, std::shared_ptr<Car<double>>> carMap = {
      {1, car_1}, {2, car_2}, {3, car_3}};

  show(carMap);

  // Find car by position
  double searchPos = 2.3;
  int carID = find(carMap, searchPos);
  if (carID != -1) {
    std::cout << "Car with position: " << searchPos << ", has ID: " << carID
              << std::endl;
  } else {
    std::cout << "No car found with position: " << searchPos << std::endl;
  }

  return 0;
}
