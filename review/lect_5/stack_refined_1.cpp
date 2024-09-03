#include <iostream>
#include <string.h>
// #include <memory> // This is for shared ptr
using namespace std;

struct Node {
  int student_no;
  char student_name[50];
  // shared_ptr<Node> next;
  Node *next;

  // Constructor
  Node() { cout << "[Success] A node is created." << endl; }

  // Destructor
  ~Node() { cout << "[Success] A node is deleted" << endl; }
};

class Stack {
private:
  // shared_ptr<Ndode> top;
  Node *top;

public:
  // Constructor
  Stack() {
    this->top = NULL;
    cout << "[Success] The Stack is generated." << endl;
  }

  // Destructor
  ~Stack() {
    while (this->top != NULL) {
      pop();
    }
    cout << "[Removed] The Stack is deleted." << endl;
  }

  void push(int n, char name[]);
  void pop();
  void display();
};

int main() {
  Stack student;
  char ch;
  int student_no;
  char student_name[50];

  do {
    int n;

    cout << "ENTER CHOICE\n"
         << "1.Push\n"
         << "2.Pop\n"
         << "3.Display\n";
    cout << "Make a choice: ";
    cin >> n;

    switch (n) {
    case 1:
      cout << "Enter details of the element to be pushed: \n";
      cout << "Roll Number: ";
      cin >> student_no;
      cout << "Enter Name: ";
      std::cin.ignore(1); // to absort '\n' newline input
      cin.getline(student_name, 50);

      // push data into the stack
      student.push(student_no, student_name);
      break;

    case 2:
      // pop data from stack
      student.pop();
      break;

    case 3:
      // display data
      student.display();
      break;

    default:
      cout << "Invalid Choice\n";
    }

    cout << "Do you want to continue? : ";
    cin >> ch;

  } while (ch != 'n' && ch != 'N');

  return 0;
}

// Functions

void Stack::push(int n, char name[]) {
  Node *newNode = new Node;
  // auto newNode = make_shared<Node>();

  // Fill data part
  newNode->student_no = n;
  strcpy(newNode->student_name, name);

  // Link part
  newNode->next = this->top;

  // Make newNode as top/head
  this->top = newNode;
}

void Stack::pop() {
  if (this->top == NULL) {
    cout << "[Warning] List is empty" << endl;
    return;
  }

  Node *temp;
  cout << top->student_name << " is removed." << endl;
  temp = top;
  top = top->next;
  delete temp;
}

void Stack::display() {
  if (top == NULL) {
    cout << "[Warning] List is empty" << endl;
    return;
  }

  // shared_ptr<Node> temp = this->top;
  Node *temp = this->top;
  while (temp != NULL) {
    cout << temp->student_no << " ";
    cout << temp->student_name << " ";
    cout << endl;
    temp = temp->next;
  }
  cout << endl;
}
