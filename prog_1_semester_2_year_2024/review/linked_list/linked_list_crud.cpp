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

void add(Node **p, Node *n) {
  n->next = *p;
  *p = n;
}

int main() {
  Node a(3), b(5), c(6);
  Node *pointer;

  a.next = &b;
  b.next = &c;

  Node *d = new Node(7);
  pointer = &a;

  // Add a node at starting position
  Node *last = pointer;
  pointer = d;
  d->next = last;

  // Delete a node at starting position
  Node *temp = pointer->next;
  delete (pointer);
  pointer = temp;

  Node *traverse;

  traverse = pointer;
  int target = 5;
  int change_to = 9;
  int i = 0;
  int found = 0;

  while (traverse != NULL) {
    if (traverse->v == target) {
      found = 1;
      traverse->v = change_to;
      break;
    } else {
      traverse = traverse->next;
      i++;
    }
  }

  if (found == 1) {
    cout << "Found target " << target << ", at " << i << endl;
  } else {
    cout << "Target not found!" << endl;
  }

  cout << "Start -> ";
  while (pointer->next != NULL) {
    cout << pointer->v << " -> ";
    pointer = pointer->next;
  }

  cout << pointer->v << " -> NULL" << endl;

  return 0;
}
