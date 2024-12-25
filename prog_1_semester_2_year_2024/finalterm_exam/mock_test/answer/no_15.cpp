#include <iostream>
#include <vector>

class MyString {
private:
  std::vector<char> str;

public:
  MyString(const char *s = "") {
    while (*s) {
      str.push_back(*s);
      ++s;
    }
    str.push_back('\0');
  }

  MyString operator+(const MyString &other) {
    MyString result;

    for (char ch : str) {
      result.str.push_back(ch);
    }

    for (char ch : other.str) {
      result.str.push_back(ch);
    }
    return result;
  }

  MyString &operator=(const MyString &other) {
    if (this == &other) {
      return *this;
    }

    str = other.str;
    return *this;
  }

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

  a = a + b;
  c = a;

  a.display();
  b.display();
  c.display();

  return 0;
}
