#include <iostream>
#include <string>
using namespace std;

class Book {
public:
  string title, author;
  int year;

  Book(string title = "", string author = "", int year = 0)
      : title(title), author(author), year(year) {}
};

class Library {
public:
  // Function to get array of books
  Book *get_books(int count) {
    if (count > 5)
      count = 5;

    static Book books[5];

    int i;
    for (i = 0; i < count; i++) {
      books[i] = Book("Title " + to_string(i + 1), "Author " + to_string(i + 1),
                      2000 + i);
    }
    return books;
  }
};

void Display(Book *books, int count) {
  int i;
  for (i = 0; i < count; i++) {
    cout << "Book: " << (i + 1) << endl;
    cout << "Title: " << books[i].title << endl;
    cout << "Author: " << books[i].author << endl;
    cout << "Year: " << books[i].year << endl;
    cout << endl;
  }
}

int main() {
  Library library;

  int count = 3;
  Book *books = library.get_books(count);

  Display(books, count);

  return 0;
}
