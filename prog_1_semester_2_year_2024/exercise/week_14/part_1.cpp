#include <iostream>
#include <list>
#include <memory>

template <typename T> class Car {
public:
  T pos;

  Car(T position) : pos(position) {}
};

// Function to display car position
template <typename T>
void show(const std::list<std::shared_ptr<Car<T>>> &cars) {
  for (const auto &car : cars) {
    std::cout << "Car Position: " << car->pos << std::endl;
  }
}

int main() {
  auto car_1 = std::make_shared<Car<double>>(1.2);
  auto car_2 = std::make_shared<Car<double>>(2.3);
  auto car_3 = std::make_shared<Car<double>>(3.5);

  std::list<std::shared_ptr<Car<double>>> carList = {car_1, car_2, car_3};

  show(carList);

  return 0;
}
