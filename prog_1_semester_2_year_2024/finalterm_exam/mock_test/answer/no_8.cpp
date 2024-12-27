#include <iostream>
#include <list>
#include <map>
#include <vector>

// Part 1: STL Array with sum function
template <typename T, size_t N> T calculateSum(const T (&arr)[N]) {
  T sum = 0;
  for (size_t i = 0; i < N; ++i) {
    sum += arr[i];
  }
  return sum;
}

// Part 2: STL List with sum function
template <typename T> T calculateSum(const std::list<T> &lst) {
  T sum = 0;
  for (typename std::list<T>::const_iterator it = lst.begin(); it != lst.end();
       ++it) {
    sum += *it;
  }
  return sum;
}

// Part 3: STL Vector with SearchVector function
template <typename T>
T SearchVector(const std::vector<T> &vec, const T &value) {
  for (size_t i = 0; i < vec.size(); ++i) {
    if (vec[i] == value) {
      return vec[i];
    }
  }
  return static_cast<T>(-1);
}

// Part 4: Handle char type with array
template <size_t N> void displayChars(const char (&arr)[N]) {
  for (size_t i = 0; i < N; ++i) {
    std::cout << arr[i];
  }
  std::cout << std::endl;
}

// Part 5: STL Map with key search by value function
template <typename K, typename V>
K findKeyByValue(const std::map<K, V> &m, const V &value) {
  for (typename std::map<K, V>::const_iterator it = m.begin(); it != m.end();
       ++it) {
    if (it->second == value) {
      return it->first;
    }
  }
  return static_cast<K>(-1); // Assume K is numeric if -1 is used
}

int main() {
  // Part 1: Array example
  int arr[] = {1, 2, 3, 4, 5};
  std::cout << "Sum of array elements: " << calculateSum(arr) << std::endl;

  // Part 2: List example
  std::list<double> lst;
  lst.push_back(1.1);
  lst.push_back(2.2);
  lst.push_back(3.3);
  std::cout << "Sum of list elements: " << calculateSum(lst) << std::endl;

  // Part 3: Vector example
  std::vector<int> vec;
  vec.push_back(10);
  vec.push_back(20);
  vec.push_back(30);
  vec.push_back(40);
  int searchValue = 30;
  std::cout << "Search result in vector: " << SearchVector(vec, searchValue)
            << std::endl;

  // Part 4: Char array example
  char charArr[] = {'H', 'e', 'l', 'l', 'o', '!'};
  std::cout << "Characters in array: ";
  displayChars(charArr);

  // Part 5: Map example
  std::map<int, std::string> myMap;
  myMap[1] = "Apple";
  myMap[2] = "Banana";
  myMap[3] = "Cherry";
  std::string searchVal = "Banana";
  int key = findKeyByValue(myMap, searchVal);
  if (key == -1) {
    std::cout << "Value not found in map." << std::endl;
  } else {
    std::cout << "Key for value '" << searchVal << "': " << key << std::endl;
  }

  return 0;
}
