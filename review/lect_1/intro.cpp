#include <iostream>

int main() {
  int i = 0, j = 0;

  std::cout << "Welcome to C++!\n";
  std::cout << "Hello world" << std::endl;
  std::cout << "Press Ctrl + D to exit end of file\n";

  // std::cout << "Enter two numbers (seperated with whitespace): ";
  // std::cin >> i >> j;

  // continuesly input number until end of files (Ctrl + D on Linux/MacOS)
  while (std::cin >> j) {
    i += j;
  }

  std::cout << "The sum of two numbers: " << i << std::endl;

  return 0;
}
