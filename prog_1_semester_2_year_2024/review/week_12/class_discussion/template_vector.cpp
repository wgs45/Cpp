#include <iostream>
#include <vector>
using namespace std;

void show(vector<char> &v) {
  int i;
  for (i = 0; i < v.size(); i++) {
    cout << v[i];
  }
  cout << endl;
}

template <class T> void show(vector<T> &v) {
  int i;
  for (i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
}

int main() {
  char str[] = "hello";
  vector<char> vc(str, str + 5);
  show(vc);

  double arr[] = {3, 12, 15};
  vector<double> vi(arr, arr + 3);
  show(vi);
  cout << endl;

  return 0;
}
