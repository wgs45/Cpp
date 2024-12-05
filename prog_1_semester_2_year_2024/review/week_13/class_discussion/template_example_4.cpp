#include <iostream>
#include <vector>

template <class T> int find_item(std::vector<T> mv, T target) {
  int i;
  for (i = 0; i < mv.size(); i++) {
    if (mv[i] == target) {
      return i;
    }
  }
  return -1;
}

int main() {
  int arr[] = {5, 7, 9};
  std::vector<int> my_vector(arr, arr + 3);
  std::cout << find_item(my_vector, 11) << std::endl;

  return 0;
}
