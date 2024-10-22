#include <iostream>
using namespace std;

class House {
  // Inner class Table represent table inside the house
  class Table {
  public:
    float width, height;
  };

  // Inner class chair represent chair inside the house
  class Chair {
  public:
    float width, height;
  };

public:
  int id; // ID for each house

  House() {} // Default constructor for the House class

  // Parameterized constructor for House
  House(int id) {
    int i;
    this->id = id; // Assign ID to each house
    for (i = 0; i < 5; i++) {
      table[i].width = i * 2;
      table[i].height = i * 3;
      chair[i].width = i;
      chair[i].width = i * 2;
    }
  }

private:
  Table table[5];
  Chair chair[5];

  // Function to access private members
  friend void show_house(House &);
};

void show_house(House &h) {
  int i;
  cout << "For house id: " << h.id << endl;
  cout << endl;
  for (i = 0; i < 5; i++) {
    cout << "The height of the chair " << i << " is " << h.chair[i].height
         << endl;
    cout << "The width of the chair " << i << " is " << h.chair[i].width
         << endl;
    cout << "The height of the table " << i << " is " << h.table[i].height
         << endl;
    cout << "The width of the table " << i << " is " << h.table[i].width
         << endl;
    cout << endl;
  }
}

int main() {
  House house[2];

  int i;
  for (i = 0; i < 2; i++) {
    house[i] = House(i);
    show_house(house[i]);
  }

  return 0;
}
