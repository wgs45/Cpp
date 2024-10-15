#include <iostream>
using namespace std;

class Node {
public:
  int v;
  Node *next;
  Node(int k) {
    v = k;
    next = NULL;
  }
};

int main() {
  Node a(3), b(5), c(6);
  Node *pointer;

  a.next = &b;
  b.next = &c;

  Node *d = new Node(7);
  c.next = d;

  pointer = &a;

  cout << "Start -> ";
  while (pointer->next != NULL) {
    cout << pointer->v << " -> ";
    pointer = pointer->next;
  }

  cout << pointer->v << " -> NULL" << endl;

  return 0;
}
