#include "sales_item.h"
#include <iostream>

int main() {
  Sales_item book, item1, item2;

  // read ISBN, number of copies sold and sales price
  std::cin >> book;
  std::cin >> item1 >> item2;
  // write ISBN, number of copies sold, total revenue and average prices
  std::cout << "Book: " << book << std::endl;

  // check if both item 1 and item 2 represent the same book
  if (item1.isbn() == item2.isbn()) {
    std::cout << "Total: " << item1 + item2 << std::endl;
    return 0;
  } else {
    std::cerr << "Data must refer to the same ISBN" << std::endl;
    return -1;
  }

  return 0;
}
