#include <iostream>
#include <queue>
using namespace std;

int main() {
  queue<int> q;
  int count = 0, input;

  cout << "Input (ctrl+d to exit): " << endl;
  while (cin >> input) {
    count++;
    q.push(input);
    if (count % 4 == 0) {
      q.pop();
    }
  }

  while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }

  return 0;
}
