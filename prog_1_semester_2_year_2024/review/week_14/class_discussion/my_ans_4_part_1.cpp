#include <iostream>
#include <queue>
using namespace std;

int main() {
  string input;

  cout << "Input: " << endl;
  getline(cin, input); // Read input sequence as string

  queue<int> q;
  int count = 0; // Used to count the 4th multiple

  for (char c : input) {
    if (isdigit(c)) { // Ensures its a valid number
      int num = c - '0';
      q.push(num); // Add number to the queue
      count++;

      if (count % 4 == 0) {
        q.pop(); // Pop the front most element if its the 4th multiple
      }
    }
  }

  // Print the remaining elements in the queue
  while(!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }
  
  cout << endl;

  return 0;
}