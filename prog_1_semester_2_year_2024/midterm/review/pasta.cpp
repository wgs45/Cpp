#include <iostream>
using namespace std;

class Pasta {
private:
  int quantity;

public:
  Pasta() : quantity(0) {}

  friend istream &operator>>(istream &input, Pasta &p) {
    cout << "Enter the quantity of pasta: ";
    input >> p.quantity;
    return input;
  }

  friend ostream &operator<<(ostream &output, Pasta &p) {
    output << "The quantity of pasta: " << p.quantity;
    return output;
  }

  Pasta operator+(const Pasta &p) const {
    Pasta temp;
    temp.quantity = this->quantity + p.quantity;
    return temp;
  }
};

int main() {
  Pasta pasta_1, pasta_2, pasta_3;

  cin >> pasta_1;
  cin >> pasta_2;

  pasta_3 = pasta_1 + pasta_2;
  cout << "Pasta 1: " << pasta_1 << endl;
  cout << "pasta_2: " << pasta_2 << endl;
  cout << "pasta_3: " << pasta_3 << endl;

  return 0;
}
