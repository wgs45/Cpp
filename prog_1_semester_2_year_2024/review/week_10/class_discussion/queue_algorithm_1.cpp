#include <iostream>
using namespace std;

// Program to implement Queue algorithm

class Queue {
public:
  int data[10000] = {0};
  int front, rear;

  Queue() {
    front = -1;
    rear = -1;
  }

  void push(int x) {
    rear++;
    data[rear] = x;
  }

  int pop() {
    if (front < rear) {
      front++;
      return data[front];
    } else {
      return -1;
    }
  }
};

int main() {
  Queue queue_1;

  queue_1.push(1), queue_1.push(3), queue_1.push(5);
  cout << queue_1.pop() << endl;
  cout << queue_1.pop() << endl;

  return 0;
}
