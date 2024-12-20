#include <iostream>
#include <vector>
using namespace std;

template <class T> class MyArray {
private:
  std::vector<int> data;

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
  MyArray<int> array_1;
  array_1.add(5);
  array_1.add(6);
  array_1.print();

  MyArray<char> array_2;
  array_2.add('g');
  array_2.add('o');
  array_2.print();

  return 0;
}
