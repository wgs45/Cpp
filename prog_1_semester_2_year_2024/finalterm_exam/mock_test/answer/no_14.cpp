#include <iostream>
using namespace std;

class Animal {
public:
  virtual void move(int) = 0;
  friend int compare(Animal &, Animal &);

protected:
  double position;
};

class Turtle : public Animal {
public:
  Turtle(int p) { position = p; }
  void move(int step) { position += step; }
};

class Rabbit : public Animal {
public:
  Rabbit(int p) { position = p; }
  void move(int step) { position += step * 3; }
};

int compare(Animal &a, Animal &b) { return (a.position > b.position); }

int main() {
  Turtle t(10.5);
  Rabbit r(7.5);

  Animal &a1 = t;
  Animal &a2 = r;

  a1.move(3);
  a2.move(5);

  if (compare(a1, a2)) {
    cout << "Turtle wins!" << endl;
  } else {
    cout << "Rabbit wins!" << endl;
  }

  return 0;
}
