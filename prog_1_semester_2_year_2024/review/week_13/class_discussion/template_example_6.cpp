#include <iostream>
using namespace std;

template <class T, size_t N> class Array {
public:
  T elements[N];
  size_t current;
  Array() { current = 0; }

  void add(const T &element) {
    if (current < N) {
      elements[current] = element;
      current++;
    }
  }

  size_t size() const { return current; }

  const T *getElements() const { return elements; }
};

template <class T, size_t N> T cal(Array<T, N> container) {
  T sum = 0;
  const T *elements = container.getElements();
  for (size_t i = 0; i < container.size(); ++i) {
    sum += elements[i];
  }
  return sum;
}

template <size_t N> void cal(Array<char, N> container) {
  int i;

  cout << N << endl;
  for (i = 0; i < N; i++) {
    cout << container.elements[i];
  }
}

int main() {
  Array<char, 5> ca;
  ca.add('H');
  ca.add('e');
  ca.add('l');
  ca.add('l');
  ca.add('o');
  cal(ca);

  cout << endl;

  return 0;
}
