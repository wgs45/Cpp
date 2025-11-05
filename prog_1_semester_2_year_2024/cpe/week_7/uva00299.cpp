// OnlineJudge uva 00299
#include <iostream>
using namespace std;

int main() {
  int cases; // Number of test cases
  cin >> cases;

  while (cases--) {
    int num_of_carriage; // Number of train carriages
    int train[50];       // Array to store the train numbers
    int swap_count = 0;  // Counts number of swaps (bubble sort)

    // Step 1: Read number of carriages
    cin >> num_of_carriage;

    // Step 2: Read each carriage’s number
    for (int i = 0; i < num_of_carriage; i++) {
      cin >> train[i];
    }

    // Step 3: Perform bubble sort to count swaps
    // Bubble sort works by repeatedly swapping adjacent elements
    // if they are out of order.
    for (int i = 0; i < num_of_carriage - 1; i++) {
      for (int j = 0; j < num_of_carriage - 1 - i; j++) {
        if (train[j] > train[j + 1]) {
          // Swap elements
          int temp = train[j];
          train[j] = train[j + 1];
          train[j + 1] = temp;
          // Count this swap
          swap_count++;
        }
      }
    }

    // Step 4: Output result for this case
    cout << "Optimal train swapping takes " << swap_count << " swaps." << endl;
  }

  return 0;
}
