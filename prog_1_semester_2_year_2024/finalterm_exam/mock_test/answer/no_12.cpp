#include <iostream>
#include <list>
#include <map>

// Template class Car template
template <typename T> class Car {
private:
  T pos;

public:
  Car(T position) : pos(position) {}
  T getPos() const { return pos; }
};

// Part 1: Show function for std::list
template <typename T> void show(const std::list<Car<T> *> &carList) {
  for (const auto &car : carList) {
    std::cout << "Car position: " << car->getPos() << std::endl;
  }
}

// Part 2: Show function for std::map
template <typename T> void show(const std::map<int, Car<T> *> &carMap) {
  for (const auto &pair : carMap) {
    std::cout << "Car ID: " << pair.first
              << ", position: " << pair.second->getPos() << std::endl;
  }
}

// Part 2: Find function
template <typename T>
int find(const std::map<int, Car<T> *> &carMap, T coordinate) {
  for (const auto &pair : carMap) {
    if (pair.second->getPos() == coordinate) {
      return pair.first;
    }
  }
  return -1;
}

int main() {
  // Part 2: using std::list
  std::list<Car<double> *> carList;
  carList.push_back(new Car<double>(1.2));
  carList.push_back(new Car<double>(2.3));
  carList.push_back(new Car<double>(3.5));

  std::cout << "Displaying car positions from list: " << std::endl;
  show(carList);

  // Clean up dynamically for list
  for (auto car : carList) {
    delete car;
  }

  // Part 2: using std::map
  std::map<int, Car<double> *> carMap;
  carMap[101] = new Car<double>(1.2);
  carMap[102] = new Car<double>(2.3);
  carMap[103] = new Car<double>(3.5);

  double searchPos = 2.3;
  int carID = find(carMap, searchPos);
  if (carID == -1) {
    std::cout << "Car with position: " << searchPos << "not found!"
              << std::endl;
  } else {
    std::cout << "Car with position: " << searchPos << " has ID: " << carID
              << std::endl;
  }

  for (auto pair : carMap) {
    delete pair.second;
  }

  return 0;
}
