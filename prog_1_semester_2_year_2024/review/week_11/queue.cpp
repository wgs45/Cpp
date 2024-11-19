#include <iostream>
#include <queue>
using namespace std;

int main() {
  queue<int> q; // stl queue

  q.push(3);
  q.push(5);
  q.push(7);

  queue<int> t = q;
  while (!t.empty()) {
    cout << t.front() << " ";
    t.pop();
  }

  return 0;
}
