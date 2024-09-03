#include <iostream>
// #include <memory> // this is used for shared_ptr
#include <string.h>
using namespace std;

struct Node {
  int student_no;
  char student_name[50];
  // shared_ptr<Node> next;
  Node *next; // tbe conventional way
};

class Stack {
private:
  // shared_ptr<node> top;
  Node *top; // the conventional way

public:
  // constructor
  Stack() {
    this->top = NULL;
    cout << "# The stack is geenerated. " << endl;
  }

  // destructor
  ~Stack() { cout << "# The stack is deleted. " << endl; }

  void push(int n, char name[]);
  void pop();
  void display();
};

int main() {
  Stack s;
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
      cout << "Roll numbers: ";
      cin >> student_no;
      cout << "Enter name: ";
      std::cin.ignore(1); // to absort '\n' newline input
      cin.getline(student_name, 50);

      // push data into the Stack
      s.push(student_no, student_name);
      break;

    case 2:
      // pop data from Stack
      s.pop();
      break;

    case 3:
      // display data
      s.display();
      break;

    default:
      cout << "Invalid choice\n";
    }

    cout << "Do you want to continue? ";
    cin >> ch;

  } while (ch != 'n' && ch != 'N');

  return 0;
}

void Stack::push(int n, char name[]) {
  Node *newNode = new Node; // the conventional way
  // auto newNode = shared_ptr<node>();

  // fill data part
  newNode->student_no = n;
  strcpy(newNode->student_name, name);

  // link part
  newNode->next = this->top;

  // make new node as head/top
  this->top = newNode;
}

void Stack::pop() {
  if (this->top == NULL) {
    cout << "List is empty!" << endl;
    return;
  }

  cout << top->student_name << " is removed." << endl;
  top = top->next;
}

void Stack::display() {
  if (top == NULL) {
    cout << "List is empty!" << endl;
    return;
  }

  // shared_ptr<node> temp = this -> top;
  Node *temp = this->top; // the conventional way
  while (temp != NULL) {
    cout << temp->student_no << " ";
    cout << temp->student_name << " ";
    cout << endl;
    temp = temp->next;
  }
  cout << endl;
}
