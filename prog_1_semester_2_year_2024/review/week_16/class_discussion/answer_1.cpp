#include <iostream>
#include <vector>

class MyString {
private:
  std::vector<char> str; // Vector to store characters

public:
  // Constructor to initalize string from a C-string
  MyString(const char *s = "") {
    while (*s) {
      str.push_back(*s); // Add each character to the vector
      ++s;
    }
    str.push_back('\0');
  }

  // Overload the + operatro for string concatenation
  MyString operator+(const MyString &other) {
    MyString result; // Empty result object

    // Copy current string into result
    for (char ch : str) {
      result.str.push_back(ch);
    }

    // Concatenate the other string into result
    for (char ch : other.str) {
      result.str.push_back(ch);
    }
    return result;
  }

  // Overload the = operator for assignment
  MyString &operator=(const MyString &other) {
    if (this == &other) {
      return *this;
    }

    str = other.str; // Copy the vector content
    return *this;
  }

  // Function to display the string
  void display() const {
    for (char ch : str) {
      std::cout << ch;
    }
    std::cout << std::endl;
  }
};

int main() {
  MyString a("Hello");
  MyString b("World");
  MyString c;

  a = a + b; // Concatenate a and b;
  c = a;

  a.display();
  b.display();
  c.display();

  return 0;
}
