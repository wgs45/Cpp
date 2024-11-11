#include <iostream>
using namespace std;

// Template function to display element of array
template <typename T> void show_arr(T a[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

int main() {
  int arr1[] = {1, 2, 3};
  double arr2[] = {1.1, 2.2, 3.3};
  show_arr(arr1, 3);
  show_arr(arr2, 3);

  return 0;
}
