#include <iostream>
using namespace std;

class ATM; // Forward declaration

class Person {
private:
  string name;
  double balance;

public:
  Person(string n, double b) : name(n), balance(b) {}

  friend class ATM;
};

class ATM {
public:
  void deposit(Person &p, double amount) {
    p.balance += amount;
    cout << "Depost amount: " << amount << endl;
    cout << "Current balance: " << p.balance << endl;
  }

  void withdraw(Person &p, double amount) {
    if (p.balance < amount) {
      cout << "Insufficient balance!" << endl;
    } else {
      p.balance -= amount;
      cout << "Withdrawn amount: " << amount << endl;
      cout << "Current balance: " << p.balance << endl;
    }
  }
};

int main() {
  Person person_1("Alpha", 1000.0);
  ATM atm;

  atm.deposit(person_1, 2000.0);
  atm.withdraw(person_1, 2000.0);

  return 0;
}
