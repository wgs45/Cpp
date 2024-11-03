#include <iostream>
using namespace std;

class House {
  class Chair {
  public:
    float width, height;
  };

  class Table {
  public:
    float width, height;
  };

public:
  int id; // ID for each House

  House() {} // default constructor

  // Parameterized constructor
  House(int id) {
    int i;
    this->id = id; // Assign id to each house
    for (i = 0; i < 5; i++) {
      chair[i].width = i * 2;
      chair[i].height = i * 3;
      table[i].width = i;
      table[i].height = i * 2;
    }
  }

private:
  Chair chair[5];
  Table table[5];

  friend void show_house(House &);
};

void show_house(House &h) {
  int i;
  cout << "For house id: " << h.id << endl;
  for (i = 0; i < 5; i++) {
    cout << "The width of chair: " << i << " is " << h.chair[i].width << endl;
    cout << "The height of chair: " << i << " is " << h.chair[i].height << endl;
    cout << "The width of table: " << i << " is " << h.table[i].width << endl;
    cout << "The height of table: " << i << " is " << h.chair[i].height << endl;
  }
}

int main() {
  House house_1[2];

  int i;
  for (i = 0; i < 2; i++) {
    house_1[i] = House(i);
    show_house(house_1[i]);
  }

  return 0;
}
