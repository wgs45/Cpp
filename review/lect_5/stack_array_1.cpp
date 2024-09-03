#include <iostream>
#include <cstdlib>
using namespace std;

// Define the default capacity of the Stack
#define SIZE 10

class Stack {
    int *arr;
    int top;
    int capacity;

public:
    Stack(int size = SIZE); // Constructor
    ~Stack(); // Destructor

    void push(int);
    int pop();
    int peek();

    int size();
    bool isEmpty();
    bool isFull();
};

// Constructor to initialize the Stack
Stack::Stack(int size) {
    arr = new int[size];
    capacity = size;
    top = -1;
}

// Destructor to free memory allocated to the Stack
Stack::~Stack() {
    delete[] arr;
}

// Utility function to add an element `x` to the Stack
void Stack::push(int x) {
    if (isFull()) {
        cout << "Overflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Inserting " << x << endl;
    arr[++top] = x;
}

// Utility function to pop a top element from the Stack
int Stack::pop() {
    // check for Stack underflow
    if (isEmpty()) {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Removing " << peek() << endl;

    // Decrease Stack size by 1 and (optionally) return the popped element
    return arr[top--];
}

// Utility function to return the top element of the Stack
int Stack::peek() {
    if (!isEmpty()) {
        return arr[top];
    } else {
        exit(EXIT_FAILURE);
    }
}

// Utility function to return the size of the Stack
int Stack::size() {
    return top + 1;
}

// utility function to check if the Stack is empty or not
bool Stack::isEmpty() {
    return top == -1;
    // or return size() == 0
}

// Utility function to check if the Stack is full or not
bool Stack::isFull() {
    return top == capacity - 1;
    // of return sizr() = capacity
}

int main() {
    Stack pt(3);

    pt.push(1);
    pt.push(2);

    pt.pop();
    pt.pop();

    pt.push(3);

    cout << "The top element is " << pt.peek() << endl;
    cout << "The Stack size is " << pt.size() << endl;

    pt.pop();

    if (pt.isEmpty()) {
        cout << "The Stack is empty" << endl;
    } else {
        cout << "The Stack is not empty" << endl;
    }

    return 0;
}


