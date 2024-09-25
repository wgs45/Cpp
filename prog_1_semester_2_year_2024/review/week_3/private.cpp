#include <iostream>
#include <string.h>
using namespace std;

class Account {
public:
  char username[50];

private:
  int money;

public:
  Account() { money = 0; }
  void deposit(int amount) { money += amount; }
  void show_money() { cout << money << endl; }
};

int main() {
  Account obj_1;

  strcpy(obj_1.username, "Alpha");

  // Error because it cannot access private variable
  // cout << obj_1.money(); << endl;

  cout << "[Input] Deposit $100 + $20..." << endl;
  obj_1.deposit(100);
  obj_1.deposit(20);

  cout << "[Output] Display current money: ";
  obj_1.show_money();

  return 0;
}
