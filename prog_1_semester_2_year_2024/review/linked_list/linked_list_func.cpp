#include <iostream>
using namespace std;

// pp => pointer to pointer

class Node {
public:
  int v;
  Node *next;

  // Constructor to initialize node value and next pointer
  Node(int k) {
    v = k;
    next = NULL;
  }
};

// Function to add a node at the beginning of the linked list
void add(Node **pp, Node *n) {
  n->next = *pp; // New node points to the current head
  *pp = n;       // Update head to the new node
}

// Function to remove a node from the linked list
void remove(Node **pp, Node *n) {
  Node *t = *pp; // Temporary pointer to traverse the list

  // Traverse the list until we find the node before the one to remove
  while (t != NULL) {
    if (t->next == n) {  // Found the node before the one to remove
      t->next = n->next; // Bypass the node to remove
      delete n;          // Free the memory of the removed node
      break;
    }
    t = t->next; // Move to the next node
  }
}

// Function to find a node by value in the linked list
int find(Node *pp, int value) {
  Node *t = pp; // Temporary pointer to traverse the list
  int i = 0;    // Index counter

  // Traverse the list
  while (t != NULL) {
    if (t->v == value) { // If the node's value matches
      return i;          // Return the index
    }
    i++;
    t = t->next;
  }
  return -1; // Return -1 if the value is not found
}

// Function to edit a node's value in the linked list
void edit(Node *pp, int old, int new_value) {
  Node *t = pp; // Temporary pointer to traverse the list

  // Traverse the list and update the value if found
  while (t != NULL) {
    if (t->v == old) {
      t->v = new_value;
    }
    t = t->next;
  }
}

// Function to display the entire linked list
void show(Node *pp) {
  cout << "Start -> ";
  Node *t = pp; // Temporary pointer to traverse the list

  // Traverse the list and print each node's value
  while (t != NULL) {
    cout << t->v << " -> ";
    t = t->next;
  }
  cout << "NULL" << endl;
}

int main() {
  Node *pointer = NULL; // Head of the linked list initialized to NULL

  // Create some nodes
  Node a(3), b(5), c(6);
  Node *d = new Node(7);

  // Add nodes to the list
  add(&pointer, &a);
  add(&pointer, &b);
  add(&pointer, &c);
  add(&pointer, d);

  // Remove node 'c' from the list
  remove(&pointer, &c);

  // Edit node with value 5 to 10
  edit(pointer, 5, 10);

  // Display the linked list
  show(pointer);

  // Find the position of the node with value 3
  int position = find(pointer, 3);
  cout << "Found 3 at: " << position << endl;

  return 0;
}
