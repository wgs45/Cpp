#include <iostream>
#include <stdlib.h>
using namespace std;

class Food {
public:
  int price, calories;

  Food() {
    price = 0;
    calories = 0;
  }

  Food(int a, int b) {
    price = a;
    calories = b;
  }
};

int main() {
  Food *food_1 = new Food[10];

  int i = 0;
  for (i = 0; i < 10; i++) {
    food_1[i].calories = i;
  }

  for (i = 0; i < 10; i++) {
    cout << "Food 1 calories: " << food_1[i].calories << endl;
  }

  cout << endl;

  Food food_2[] = {Food(1, 2), Food(2, 3)};
  cout << "Food 2[0] calories: " << food_1[0].calories << endl;
  cout << "Food 2[1] calories: " << food_2[1].calories << endl;

  cout << endl;

  Food *food_3 = (Food *)malloc(10 * sizeof(Food));

  for (i = 0; i < 10; i++) {
    food_3[i] = Food(i * 2, i * 3);
  }

  for (i = 0; i < 10; i++) {
    cout << "Food 3 price: " << food_3[i].price << endl;
    cout << "Food 3 calories: " << food_3[i].calories << endl;
  }

  return 0;
}
