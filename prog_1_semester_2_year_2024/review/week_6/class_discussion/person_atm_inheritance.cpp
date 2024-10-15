#include <iostream>
#include <string>
using namespace std;

class ATM; // Forward declaration of ATM Class

class Person {
private:
  string name;
  double balance;

public:
  Person(string n, double b) : name(n), balance(b) {}

  friend class ATM; // Friend class
};

class ATM {
public:
  void deposit(Person &p, double amount) {
    p.balance += amount;
    cout << "Deposit: " << amount << endl;
    cout << "New balance: " << p.balance << endl;
  }

  void withdraw(Person &p, double amount) {
    if (amount > p.balance) {
      cout << "Insufficient balance: " << amount << endl;
    } else {
      p.balance -= amount;
      cout << "Withdrawn: " << amount << endl;
      cout << "New balance: " << p.balance << endl;
    }
  }
};

int main() {
  Person person_1("Alpha", 1000.0);
  ATM atm;

  atm.deposit(person_1, 500.0);
  atm.withdraw(person_1, 1000.0);

  return 0;
}
