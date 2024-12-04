#include <iostream>
#include <string>
#define SIZE 15
// using namespace std;

// Custom queue classs with a template to support different data types
template <class T> class CustomQueue {
  T *arr; // Dynamic array to store elements
  int capacity, front, rear, count;

public:
  // Initialized constructor with the given size value
  CustomQueue(int size = SIZE);

  // Destructor to free dynamically allocated memory
  ~CustomQueue();

  // Function to remove an element from the front of the queue
  void dequeue();

  // Function to add an element to the rear of the queue
  void enqueue(T item);

  // Funtion to return the elemennt at the front of the queue
  T peek();

  int size(); // Function to return the current number of elements in the queue
  bool isEmpty(); // Function to check if queue is emptu
  bool isFull();  // Function to check if queue is full
};

// Constructor to Initializes the queue
template <class T> CustomQueue<T>::CustomQueue(int size) {
  arr = new T[size]; // Allocate memory for the queue

  // Initialized value
  capacity = size;
  front = 0;
  rear = -1;
  count = 0;
}

// Destructor to frees the allocated memmory
template <class T> CustomQueue<T>::~CostumQueue() {
  delete[] arr; // Free dynamically allocated memmory
}

// Removes an element from the front of the queue
template <class T> void CustomQueue<T>::dequeue() {
  if (isEmpty()) {
    std::cout << "Underflow\nProgram Terminated\n";
    exit(1);
  }
}

int main() {
  int i;

  return 0;
}
