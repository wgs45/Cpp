#include <iostream>
#include <queue>
using namespace std;

// Print the queue
void print_queue(queue<int> q) {
  queue<int> temp = q;
  while (!temp.empty()) {
    cout << temp.front() << " ";
    temp.pop();
  }
  cout << "\n";
};

int main() {
  queue<int> q1;
  q1.push(1);
  q1.push(2);
  q1.push(3);

  cout << "The first queue: ";
  print_queue(q1);

  queue<int> q2;
  q2.push(4);
  q2.push(5);
  q2.push(6);

  cout << "The second queue: ";
  print_queue(q2);

  cout << "Emptying the first queue: ";
  cout << q1.empty() << endl; // return 0 (false) since q1 is not empty

  return 0;
}
