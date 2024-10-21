#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

class Book {
private:
  int page, total_pages;

public:
  // Default constructor
  Book() : page(0), total_pages(0) {}

  // Constructor to initialize the book with a specified current page and total
  // page
  Book(int p, int total) : page(p), total_pages(total) {}

  // Set current page number
  void set_page(int p) {
    if (p >= 0 && p <= total_pages) {
      page = p;
    } else {
      cout << "Invalid page number!" << endl;
    }
  }

  // Display current page
  void display_page() const { cout << "Current page: " << page << endl; }

  // Turn page forward
  void turn_page_forward(int n) {
    if (n > 0 && page + n <= total_pages) {
      page += n;
    } else {
      cout << "Can't turn that many pages forward!" << endl;
    }
  }

  // Overload operator + to turn page backward
  Book operator+(int n) const {
    Book newBook(*this); // Create a copy of the current book
    if (n > 0 && page - n >= 0) {
      newBook.page -= n;
    } else {
      cout << "Can't turn that many pages backward!" << endl;
    }
    return newBook;
  }

  // Overload >> operator to specify the total number of pages
  friend istream &operator>>(istream &input, Book &b) {
    cout << "Enter the total number of pages: ";
    input >> b.total_pages;
    return input;
  }

  // Overload << operator to display the current pages
  friend ostream &operator<<(ostream &output, Book &b) {
    output << "The book has " << b.total_pages << " pages" << endl;
    return output;
  }
};

class Shelf {
private:
  Book books[10];

public:
  // Constructor to initialize each book with random page number and total pages
  Shelf() {
    srand(time(0));
    int i;
    for (i = 0; i < 10; i++) {
      int total_pages = rand() % 501 + 100; // Total pages between 100 and 600
      int current_pages =
          rand() % total_pages; // Current page between 0 and total pages
      books[i] = Book(current_pages, total_pages);
    }
  }

  void display_books() const {
    int i;
    for (i = 0; i < 10; i++) {
      cout << "Book " << i + 1 << ": ";
      books[i].display_page();
    }
  }
};

int main() {
  Shelf my_shelf;

  my_shelf.display_books();

  return 0;
}
