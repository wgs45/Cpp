#include <iostream>
#include <math.h>
using namespace std;

// Program to implement Stack algorithm

class Stack {
public:
  int data[100000] = {0};
  int top;

  Stack() { top = -1; }

  // Insert data
  void push(int x) {
    top++;
    data[top] = x;
  }

  // Pulling out data
  int pop() {
    int temp = data[top];
    top--;
    return temp;
  }
};

int main() {
  Stack stack_1;

  stack_1.push(3);
  stack_1.push(5);
  cout << stack_1.pop() << endl;

  return 0;
}
