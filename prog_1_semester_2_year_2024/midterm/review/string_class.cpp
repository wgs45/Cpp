#include <iostream>

class MyString {
private:
  char *str;
  int length;

  int strLength(const char *s) const {
    int len = 0;
    while (s[len] != '\0')
      ++len;
    return len;
  }

public:
  // Default constructor
  MyString() : str(new char[1]), length(0) { str[0] = '\0'; }

  // Constructor to initialize with a C-style string
  MyString(const char *s) : length(strLength(s)), str(new char[length + 1]) {
    for (int i = 0; i < length; ++i)
      str[i] = s[i];
    str[length] = '\0';
  }

  // Copy constructor
  MyString(const MyString &other)
      : length(other.length), str(new char[length + 1]) {
    for (int i = 0; i < length; ++i)
      str[i] = other.str[i];
    str[length] = '\0';
  }

  // Destructor
  ~MyString() { delete[] str; }

  // Overload assignment operator
  MyString &operator=(const MyString &other) {
    if (this == &other)
      return *this;
    delete[] str;
    length = other.length;
    str = new char[length + 1];
    for (int i = 0; i < length; ++i)
      str[i] = other.str[i];
    str[length] = '\0';
    return *this;
  }

  // Overload + operator for concatenation
  MyString operator+(const MyString &other) const {
    MyString result;
    result.length = length + other.length;
    result.str = new char[result.length + 1];
    for (int i = 0; i < length; ++i)
      result.str[i] = str[i];
    for (int i = 0; i < other.length; ++i)
      result.str[length + i] = other.str[i];
    result.str[result.length] = '\0';
    return result;
  }

  // Overload == operator for comparison
  bool operator==(const MyString &other) const {
    if (length != other.length)
      return false;
    for (int i = 0; i < length; ++i)
      if (str[i] != other.str[i])
        return false;
    return true;
  }

  // Overload << operator for output
  friend std::ostream &operator<<(std::ostream &os, const MyString &myStr) {
    return os << myStr.str;
  }
};

int main() {
  MyString str1("Hello");
  MyString str2("World");
  MyString str3 = str1 + str2;
  std::cout << "Concatenated String: " << str3 << std::endl;

  MyString str4 = str1;
  if (str1 == str4) {
    std::cout << "str1 is equal to str4" << std::endl;
  }
  return 0;
}
