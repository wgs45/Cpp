#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

class Student {
private:
  int scores[5];

public:
  static int passing_score;

  // Constructor to initialize score with random number between 30 and 100
  Student() {
    int i;
    for (i = 0; i < 5; i++) {
      scores[i] = rand() % 71 + 30;
    }
  }

  // Check whether student is pass or fail
  void check() const {
    cout << "Scores: ";
    int i;
    for (i = 0; i < 5; i++) {
      cout << scores[i] << " ";
    }

    cout << "\nResults: ";
    for (i = 0; i < 5; i++) {
      if (scores[i] >= passing_score) {
        cout << "Pass ";
      } else {
        cout << "Failed ";
      }
    }
  }

  // Static function to change the passing scores
  static void set_passing_score(int new_score) { passing_score = new_score; }
};

// Set passing score
int Student::passing_score = 60;

int main() {
  // Seed for generate random numbers
  srand(static_cast<unsigned int>(time(0)));

  Student student_1;
  student_1.check();

  cout << endl;

  // Change the score
  Student::set_passing_score(70);
  cout << "\nAfter changing the passing score to 70: " << endl;
  student_1.check();

  cout << endl;

  return 0;
}
