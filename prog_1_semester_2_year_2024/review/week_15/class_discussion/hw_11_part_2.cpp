#include <iostream>
#include <vector>

using namespace std;

template <class T> class MyArray {

private:
  std::vector<T> data;

public:
  void add(T value) { data.push_back(value); }
  void print() {
    int i;
    for (i = 0; i < data.size(); i++) {
      cout << data[i] << " ";
    }
  }
};

template <> class MyArray<char> {
private:
  std::vector<char> data;

public:
  void add(char value) { data.push_back(value + 1); }
  void print() {
    int i;
    for (i = 0; i < data.size(); i++) {
      cout << data[i] << " ";
    }
  }
};

int main() {

  MyArray<int> array1;
  array1.add(5);
  array1.add(6);
  array1.print();

  MyArray<char> array2;
  array2.add('g');
  array2.add('o');
  array2.print();

  return 0;
}
