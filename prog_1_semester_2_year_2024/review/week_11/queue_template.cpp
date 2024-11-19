#include <iostream>
#include <queue>
#include <typeinfo> // Required for typeid
using namespace std;

template <class T> void show(queue<T> &tq) {
  // Create a copy of the queue to preserve the original queue
  queue<T> tt = tq;

  // Loop until the copied queue becomes empty
  while (!tt.empty()) {
    // Print the type of the element at the front of the queue
    cout << typeid(tt.front()).name() << " ";

    // Print the value of the front element
    cout << tt.front() << " ";

    // Remove the front element from the copied queue
    tt.pop();
  }
}

int main() {
  // Declare a queue of type float
  queue<float> q;

  // Add elements to the queue
  q.push(3.2); // Pushes 3.2 to the end of the queue
  q.push(4.5); // Pushes 4.5 to the end of the queue
  q.push(5.3); // Pushes 5.3 to the end of the queue

  show(q);

  return 0;
}
