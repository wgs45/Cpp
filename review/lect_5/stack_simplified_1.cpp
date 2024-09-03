#include <iostream>
#include <string.h>
using namespace std;

// Simplified Stack algorithms

struct Node {
    int student_no;
    Node *next; 
};

class Stack {
private:
    Node *top; // the conventional way

public:
    // Constructor
    Stack() {
        this -> top = NULL;
        cout << "# The stack is generated. " << endl;
    }

    // Destructor
    ~Stack() {
        cout << "# The stack is deleted. " << endl;
    }

    void push(int n);
    void pop();
    void display();
};

int main() {
    Stack st;
    int student_no;
    char c;

    cout << "Push an item: ";
    cin >> student_no;
    
    // push data into the Stack
    st.push(student_no);

    // show the Stack content
    st.display();

    cout << "Push an item: ";
    cin >> student_no;

    // Push data into the Stack (2nd)
    st.push(student_no);

    // show the Stack content
    st.display();

    cout << "Push an item: ";
    cin >> student_no;

    // Push data into the stack (3rd)
    st.push(student_no);

    // show the Stack content
    st.display();

    cout << "Press any key to continue..." << endl;
    cin.ignore(1);
    
    // pop an item 
    cout << "pop out an item: "; 
    cin.ignore(1);
    st.pop();
    //show the stack content
    st.display();
    // pop an item 
    cout << "pop out an item: "; 
    cin.ignore(1);
    st.pop();
    //show the stack content
    st.display();
    // pop an item 
    cout << "pop out an item: "; 
    cin.ignore(1);
    st.pop();

    return 0;
}

void Stack::push(int n) {
    Node *newNode = new Node; // the conventional way

    // fill data part
    newNode -> student_no = n;

    // link part
    newNode -> next = this -> top;

    // make newnode as top/head
    this -> top = newNode;
}

void Stack::pop() {
    if (this -> top == NULL) {
        cout << "List is empty!" << endl;
        return;
    }   
    Node *temp;
    cout << top -> student_no << " is removed." << endl;

    temp = top;
    top = top -> next;
    delete temp;
}

void Stack::display() {
    if (top == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    Node *temp = top; // the conventional way
    
    while (temp != NULL) {
        cout << temp -> student_no << endl;
        temp = temp -> next;
    }
    cout << endl;
}
