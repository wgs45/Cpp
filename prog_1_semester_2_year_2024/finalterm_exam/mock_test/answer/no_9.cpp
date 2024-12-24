#include <iostream>
using namespace std;

class Player {
protected:
  string name;
  int health;

public:
  virtual void attack() = 0;
};

class Enemy : public Player {
public:
  Enemy(string n, int hp) {
    this -> name = n;
    this -> health = hp;
  }

  void attack() {
    health = health - 10;
    cout << "Enemy attacks: " << this -> name << ", inflicting 10 dmg!" << endl;
    cout << this -> name << "'s health is now " << this -> health << endl << endl;
  }
};

class Knight : public Player {
public:
  Knight(string n, int hp) {
    this -> name = n;
    this -> health = hp;
  }

  void attack() {
    health = health - 20;
    cout << "Knight attacks: " << this -> name << ", inflicting 20 dmg" << endl;
    cout << this -> name << "'s health is now " << this -> health << endl;
  }
};

int main() {
  Player *player_1 = new Knight("Alpha", 100);
  player_1 -> attack();

  Player *player_2 = new Enemy("Beta", 100);
  player_2 -> attack();

  return 0;
}