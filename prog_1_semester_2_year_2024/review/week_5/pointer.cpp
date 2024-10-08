#include <iostream>
using namespace std;

class Food {
public:
  int price;
  int calories;

  Food() {
    price = 0;
    calories = 0;
  }

  Food(int a, int b) {
    price = a;
    calories = b;
  }

  ~Food() { cout << "Food deleted" << endl; }
};

int main() {
  Food *food = new Food();
  food->calories = 20;

  cout << "food -> calories: " << food->calories << endl;
  cout << "(*food).calories: " << (*food).calories << endl;
  delete (food);

  Food *food_1 = new Food(300, 60);
  food_1->calories = 30;
  cout << "food_1 -> calories: " << food_1->calories << endl;
  delete (food_1);

  return 0;
}
