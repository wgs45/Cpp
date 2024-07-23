#include <iostream>
#include <string>

class Book {
private:
  int Book_No;
  std::string Title;
  float Price;

  float Total_cost(int N) const { return N * Price; }

public:
  // function to read book no, title and price
  void input() {
    std::cout << "Enter book number: ";
    std::cin >> Book_No;
    std::cin.ignore(); // ignore newline char left in the buffer
    std::cout << "Enter book title: ";
    std::getline(std::cin, Title);
    std::cout << "Enter price: ";
    std::cin >> Price;
  }

  // function to ask the user to input the number of copies to be purchased
  void purchase() {
    int num_of_copies;
    std::cout << "Enter the number of copies to be purchased: ";
    std::cin >> num_of_copies;
    float total_cost = Total_cost(num_of_copies);
    std::cout << "Total cost to be paid: " << total_cost << std::endl;
  }
};

int main() {
  Book obj;
  obj.input();
  obj.purchase();

  return 0;
}
