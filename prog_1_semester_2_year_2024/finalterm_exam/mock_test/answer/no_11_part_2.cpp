#include <iostream>
#include <set>
using namespace std;

int main() {
  set<double> s;
  double a;
  while (cin >> a) {
    s.insert(a);
  }
  set<double>::iterator it;
  it = s.begin();
  double total = 0;
  while (it != s.end()) {
    cout << *it << " ";
    total = total + *it;
    it++;
  }
  cout << endl << total << endl;

  return 0;
}
