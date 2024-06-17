#include "sales_item.h"
#include <iostream>

int main() {
  Sales_item total; // variable to hold data for the next transaction

  // read first transaction and ensure the data is being process
  if (std::cin >> total) {
    Sales_item transaction; // variable to hold the running sum

    // read the remaining transaction
    while (std::cin >> transaction) {
      // check if the program still process the same book
      if (total.isbn() == transaction.isbn()) {
        total += transaction; // update the running total
      } else {
        // print the result of the previous book
        std::cout << "Total: " << total << std::endl;
        total = transaction;
      }
    }
    std::cout << "Total: " << total << std::endl;
  } else {
    // error handler
    std::cerr << "No data detected!" << std::endl;
    return -1;
  }

  return 0;
}
