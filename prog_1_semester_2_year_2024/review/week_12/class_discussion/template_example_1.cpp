#include <iostream>
#include <vector>
using namespace std;

// Overloaded function for vectors of type "char"
void show(vector<char> &v) {
  int i;

  // Iterate through the vector
  for (i = 0; i < v.size(); i++) {
    cout << v[i];
  }
  cout << endl;
  cout << "char" << endl; // Indicate the type of vector
}

// Overloaded function for vector of type "double"
void show(vector<double> &v) {
  int i;

  // Iterate through the vector
  for (i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
  cout << "Double" << endl; // Indicate the type of vector
}

// Template function for vector of any other type
template <class T> void show(vector<T> &v) {
  int i;

  // Iterate through the vector
  for (i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
  cout << "Neither double or char" << endl; // Indicate the type of vector
}

int main() {
  char str[] = "Hello";

  vector<char> vc(str, str + 5);
  show(vc);

  double arr[] = {3, 12.3, 3, 15.5};
  vector<double> vi(arr, arr + 4);
  show(vi);

  int arr_2[] = {1, 2, 3};
  vector<int> vd(arr_2, arr_2 + 3);
  show(vd);

  return 0;
}
