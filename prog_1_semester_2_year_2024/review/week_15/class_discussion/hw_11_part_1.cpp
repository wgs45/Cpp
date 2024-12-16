// homework 11 part 1 default answer
#include <iostream>
#include <vector>

template <class T> class MyArray {
private:
  std::vector<int> data;

public:
  void add(int value);
  void print();
};

template <class T> void MyArray<T>::add(int value) { data.push_back(value); }

template <class T> void MyArray<T>::print() {
  for (int i = 0; i < data.size(); i++) {
    std::cout << data[i] << " ";
  }
}

int main() {
  MyArray<int> array;
  array.add(1);
  array.add(2);
  array.print();
  return 0;
}
