#include <iostream>
#include <limits> // for std::numeric_limits
#include <string>
using namespace std;

struct Node {
  string student_no;
  int math;
  int english;
  int computer;
  Node *next;
};

class Stack {
private:
  Node *top;

public:
  // Constructor
  Stack() {
    this->top = NULL;
    cout << "[Generated] The Stack is generated" << endl;
  }

  // Destructor
  ~Stack() {
    while (top != NULL) {
      pop();
    }
    cout << "[Removed] The Stack is deleted" << endl;
  }

  void push(string s, int m, int e, int c) {
    Node *newNode = new Node();

    newNode->student_no = s;
    newNode->math = m;
    newNode->english = e;
    newNode->computer = c;
    newNode->next = top;
    top = newNode;
    cout << "[Pushed] Pushed Stack: " << s << endl;
  }

  void pop() {
    if (top == NULL) {
      cout << "[Error] The Stack is empty" << endl;
      return;
    }

    Node *temp = top;
    top = top->next;
    cout << "[Popped] Popped Stack: " << temp->student_no << endl;
    delete temp;

    // Calculate and print average grade
    int math_sum = 0, english_sum = 0, computer_sum = 0, count = 0;

    Node *current = top;
    while (current != NULL) {
      math_sum += current->math;
      english_sum += current->english;
      computer_sum += current->computer;
      count++;
      current = current->next;
    }

    if (count > 0) {
      cout << "[Result] Average grade after pop -> Math: "
           << static_cast<float>(math_sum) / count << endl;
      cout << "[Result] Average grade after pop -> English: "
           << static_cast<float>(english_sum) / count << endl;
      cout << "[Result] Average grade after pop -> computer: "
           << static_cast<float>(computer_sum) / count << endl;
    } else {
      cout << "[Error] The Stack is empty after the pop" << endl;
    }
  }

  void display() {
    if (top == NULL) {
      cout << "[Error] The Stack is empty" << endl;
      return;
    }

    Node *current = top;
    cout << "[Result] The Stack content: " << endl;
    while (current != NULL) {
      cout << "Student No: " << current->student_no << endl;
      cout << "Math: " << current->math << endl;
      cout << "English: " << current->english << endl;
      cout << "Computer: " << current->computer << endl;
      current = current->next;
    }
  }
};

int main() {
  Stack stu;
  string student_no;
  int math, english, computer;

  // Push first student
  cout << "[Input] Push an item: ";
  cin >> student_no >> math >> english >> computer;
  stu.push(student_no, math, english, computer);

  // Push second student
  cout << "[Input] Push an item: ";
  cin >> student_no >> math >> english >> computer;
  stu.push(student_no, math, english, computer);

  // Push third student
  cout << "[Input] Push an item: ";
  cin >> student_no >> math >> english >> computer;
  stu.push(student_no, math, english, computer);

  // Display Stack content
  stu.display();

  // pop the first item
  cout << "[Popped] pop out an item";
  cin.ignore(1);
  stu.pop();
  stu.display();

  // pop the second item
  cout << "[Popped] pop out an item";
  cin.ignore(1);
  stu.pop();
  stu.display();

  // pop the third item
  cout << "[Popped] pop out an item";
  cin.ignore(1);
  stu.pop();
  stu.display();

  // Exit
  cout << "Press any key to continue..." << endl;
  // cin.ignore(1)

  // Clears out any characters in the input buffer up to the next newline,
  // ensuring no leftover input interferes with the next input operation.
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  // Waits for the user to press Enter, which allows the program to pause and
  // display output before exiting.
  cin.get();

  return 0;
}
