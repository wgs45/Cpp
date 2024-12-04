#include <iostream>
#include <set>
using namespace std;

template <class T> void show(set<T> &k) {
  typename set<T>::iterator tt;
  for (tt = k.begin(); tt != k.end(); tt++) {
    cout << *tt << " ";
  }
}

void show(set<int> &k) { cout << 0 << endl; }

int main() {
  char str[] = "apple";
  set<char> sec(str, str + 5);

  show(sec);
  set<int> set_1;
  set_1.insert(6);
  set_1.insert(7);
  show(set_1);

  return 0;
}
