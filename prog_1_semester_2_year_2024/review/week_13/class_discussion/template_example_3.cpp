#include <iostream>
#include <list>

template <class T> T calc_sum(std::list<T> ml) {
  typename std::list<T>::iterator it;
  T sum = 0;
  it = ml.begin();
  while (it != ml.end()) {
    sum = sum + *it;
    it++;
  }
  return sum;
}

int main() {
  std::list<int> my_list;
  my_list.push_front(3);
  my_list.push_back(4);
  my_list.push_front(5);
  std::cout << calc_sum(my_list) << std::endl;

  return 0;
}
