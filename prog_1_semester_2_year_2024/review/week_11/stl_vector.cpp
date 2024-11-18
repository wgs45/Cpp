#include <iostream>
#include <vector>
using namespace std;

void print_vector(vector<int> v) {
  int i;
  for (i = 0; i < v.size(); i++) {
    cout << v[i] << ' ';
  }
  cout << endl;
};

int main() {
  vector<int> v;

  int i;
  for (i = 0; i < 5; i++) {
    v.push_back(2 * i);
  }
  print_vector(v);

  v.insert(v.begin() + 1, 9);
  print_vector(v);

  v.erase(v.begin() + 1, v.begin() + 3);
  print_vector(v);

  return 0;
}
