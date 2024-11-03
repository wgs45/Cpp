#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

class Book {
public:
  int page, total_page;

public:
  Book() : page(0), total_page(0) {}

  Book(int p, int total) : page(p), total_page(p) {}

  // Set current page number
  void set_page(int p) {
    if (p >= 0 && p <= total_page) {
      page = p;
    } else {
      cout << "Invalid page!" << endl;
    }
  }

  // Display current page
  void display_page() const { cout << "Current page: " << page << endl; }

  // Turn the page forward
  void turn_page_forward(int p) {
    if (p > 0 && page + p <= total_page) {
      page += p;
    } else {
      cout << "Unable to turn more page forward!" << endl;
    }
  }

  // Operator+ to turn page backward
  Book operator+(int p) const {
    Book newBook(*this); // Create a copy of the current book
    if (p > 0 && page - p >= 0) {
      newBook.page -= p;
    } else {
      cout << "Unable to turn more page backward!" << endl;
    }
    return newBook;
  }

  // Overload>> operator to specify the total number of pages
  friend istream &operator>>(istream &input, Book &b) {
    cout << "Enter the total number of book pages: ";
    input >> b.total_page;
    return input;
  }

  // Overload<< operator to display the current page
  friend ostream &operator<<(ostream &output, Book &b) {
    output << "The book has a total of " << b.total_page << " pages" << endl;
    return output;
  }
};

class Shelf {
private:
  Book books[10];

public:
  // Constructor to initialize randomm value
  Shelf() {
    srand(time(0));
    int i;
    for (i = 0; i < 10; i++) {
      int total_pages =
          rand() % 501 + 100; // Generate a random page from 100 to 500
      int current_pages = rand() % total_pages;
      books[i] = Book(current_pages, total_pages);
    }
  }

  void display_books() const {
    int i;
    for (i = 0; i < 10; i++) {
      cout << "Book " << i + 1 << ":";
      books[i].display_page();
    }
  }
};

int main() {
  Shelf my_shelf;
  my_shelf.display_books();

  return 0;
}
