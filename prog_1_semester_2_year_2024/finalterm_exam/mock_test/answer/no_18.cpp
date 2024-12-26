#include <ctime>
#include <iostream>
#include <string>
#include <vector>

class Card {
public:
  std::string suit;
  int number;

  Card(const std::string &suit, int number) : suit(suit), number(number) {}

  void display() const { std::cout << number << " of " << suit << std::endl; }
};

template <typename T> class Deck {
private:
  std::vector<T> cards;

public:
  void addCard(const T &card) { cards.push_back(card); }

  void displayDeck() const {
    for (const auto &card : cards) {
      card.display();
    }
  }
};

int main() {
  std::srand(static_cast<unsigned>(std::time(0)));

  std::vector<std::string> suits = {"Hearts", "Diamonds", "Clubs", "Spades"};

  Deck<Card> deck1;
  Deck<Card> deck2;
  Deck<Card> deck3;

  int i;
  for (i = 0; i < 5; i++) {
    int randomSuitIndex = std::rand() % suits.size();
    int randomNumber = (std::rand() % 13) + 1; // Card numbers from 1 to 13

    deck1.addCard(Card(suits[randomSuitIndex], randomNumber));
    randomSuitIndex = std::rand() % suits.size();
    randomNumber = (std::rand() % 13) + 1;

    deck2.addCard(Card(suits[randomSuitIndex], randomNumber));
    randomSuitIndex = std::rand() % suits.size();
    randomNumber = (std::rand() % 13) + 1;

    deck3.addCard(Card(suits[randomSuitIndex], randomNumber));
  }

  std::cout << "Deck 1 contains: " << std::endl;
  deck1.displayDeck();
  std::cout << "Deck 2 contains: " << std::endl;
  deck2.displayDeck();
  std::cout << "Deck 3 contains: " << std::endl;
  deck3.displayDeck();

  return 0;
}
