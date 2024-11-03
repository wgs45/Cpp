#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Card {
private:
  int suit, rank;

public:
  Card() {}
  Card(int s, int r) {
    suit = s;
    rank = r;
  }
  void show() { cout << suit << "," << rank << endl; }
};

class Deck {
public:
  int seq[52];
  Card carr[52];
  int card_count, current_card_pos;
  Deck() {
    srand(time(NULL));
    current_card_pos = 0;
    card_count = rand() % 10;
    int i, random;
    for (i = 0; i < 52; i++) { // 0~51
      seq[i] = i;
    }
    for (i = 0; i < 52 / 2; i++) { // shuffle
      random = rand() % 52;
      int temp = seq[i];
      seq[i] = seq[random];
      seq[random] = temp;
    }
    // for(i=0; i<52; i++){ //show suffle result;
    //	cout << seq[i] << " ";
    // }
    for (i = 0; i < card_count; i++) {
      add();
    }
  }
  void add() {
    int suit = seq[current_card_pos] % 4;
    int rank = seq[current_card_pos] / 4;
    carr[current_card_pos] = Card(suit, rank);
    current_card_pos++;
  }

  void display() {
    int i;
    for (i = 0; i < card_count; i++) {
      carr[i].show();
    }
  }
};

int main() {
  Deck d;
  d.display();
  return 0;
}
