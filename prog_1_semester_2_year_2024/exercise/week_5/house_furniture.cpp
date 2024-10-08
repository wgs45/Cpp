#include <iostream>
#include <vector>
using namespace std;

class House {
public:
  // Nested class for Table
  class Table {
  public:
    int x, y; // coordinates
    Table(int x, int y) : x(x), y(y) {}
    void Show() { cout << "Table at coordinates: " << x << ", " << y << endl; }
  };

  class Chair {
  public:
    int x, y;
    Chair(int x, int y) : x(x), y(y) {}
    void Show() { cout << "Chair at coordinates: " << x << ", " << y << endl; }
  };

private:
  int house_number;
  vector<Table> tables;
  vector<Chair> chairs;

public:
  House(int number) : house_number(number) {}

  void add_table(int x, int y) { tables.push_back(Table(x, y)); }

  void add_chair(int x, int y) { chairs.push_back(Chair(x, y)); }

  void Show() {
    cout << "House #" << house_number << " contains: " << endl;
    for (auto &table : tables) {
      table.Show();
    }

    for (auto &chair : chairs) {
      chair.Show();
    }
    cout << endl;
  }
};

int main() {
  // Create an array of house
  House houses[2] = {House(1), House(2)};

  // Add tables and chairs to house 1
  houses[0].add_table(1, 1);
  houses[0].add_chair(2, 2);
  houses[0].add_table(3, 4);

  // Add tables and chairs to house 2
  houses[1].add_table(5, 5);
  houses[1].add_chair(6, 6);
  houses[1].add_table(7, 8);

  // display output
  for (int i = 0; i < 2; i++) {
    houses[i].Show();
  }

  return 0;
}
