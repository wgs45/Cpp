#include <iostream>
using namespace std;

// Program to implement Stack algorithm

class Stack {
public:
  int data[10000] = {0};
  int top;

  Stack() { top = -1; }

  void push(int x) {
    top++;
    data[top] = x;
  }

  int pop() { return data[top--]; }
};

int main() {
  Stack stack_1;

  stack_1.push(3);
  stack_1.push(5);
  stack_1.push(7);
  cout << stack_1.pop() << endl;
  cout << stack_1.pop() << endl;

  return 0;
}
