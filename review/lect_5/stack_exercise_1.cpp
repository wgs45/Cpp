#include <iostream>
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
    cout << "[Success] The Stack is generated" << endl;
  }

  // Destructor
  ~Stack() {
    cout << "[Remove] The Stack is removed" << endl;
    while (top != NULL) {
      pop();
    }
  }

  void push(string s, int m, int e, int c);
  void pop();
  void display();
  void calculate_average();
};

int main() {
  Stack stu; // Stack stu(student)
  string student_no;
  int math, english, computer;
  char c;

  int i = 0;
  for (i = 0; i < 3; i++) {
    cout << "[Input] Push an item (format: student_no math english computer): ";
    cin >> student_no >> math >> english >> computer;
    stu.push(student_no, math, english, computer);
  }

  // Display Stack contents:
  stu.display();

  // Pop an item:
  cout << "[Remove] Pop out an item: " << endl;
  stu.pop();

  // Display Stack contents:
  stu.display();

  // Pop the last items:
  cout << "[Remove] Pop out an item: " << endl;
  stu.pop();
  stu.display();

  cout << "Press any key to continue..." << endl;
  cin.ignore();
  cin.get();

  return 0;
}

// Functions

void Stack::push(string s, int m, int e, int c) {
  Node *newNode = new Node();

  newNode->student_no = s;
  newNode->math = m;
  newNode->english = e;
  newNode->computer = c;
  newNode->next = top;
  top = newNode;
  cout << "[Success] Pushed student: " << s << " " << m << " " << e << " " << c
       << endl;
}

void Stack::pop() {
  if (top == NULL) {
    cout << "[Warning] Stack is empty, can't pop" << endl;
    return;
  }

  Node *temp = top;
  top = top->next;
  cout << "[Remove] Popped student: " << temp->student_no << endl;
  delete temp;

  calculate_average();
}

void Stack::display() {
  if (top == NULL) {
    cout << "[Warning] Stack is empty" << endl;
    return;
  }

  Node *current = top;
  cout << "[Output] Stack contents: " << endl;
  while (current != NULL) {
    cout << "Student number: " << current->student_no << endl;
    cout << "Math score: " << current->math << endl;
    cout << "English score: " << current->english << endl;
    cout << "Computer score: " << current->computer << endl;
    current = current->next; // Move to the next node
  }
}

void Stack::calculate_average() {
  if (top == NULL) {
    cout << "[Warning] Stack is empty, no averages to calculate" << endl;
    return;
  }

  Node *current = top;
  int total_math = 0, total_english = 0, total_computer = 0;
  int count = 0;

  while (current != NULL) {
    total_math += current->math;
    total_english += current->english;
    total_computer += current->computer;
    count++;
    current = current->next; // Move to the next node
  }

  double avg_math = static_cast<double>(total_math) / count;
  double avg_english = static_cast<double>(total_english) / count;
  double avg_computer = static_cast<double>(total_computer) / count;

  // Display the result
  cout << "[Output] Averages after pop:" << endl;
  cout << "Average Math score: " << avg_math << endl;
  cout << "Average English score: " << avg_english << endl;
  cout << "Average Computer score: " << avg_computer << endl;
}
