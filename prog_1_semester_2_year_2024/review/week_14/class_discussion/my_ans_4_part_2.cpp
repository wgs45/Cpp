#include <iostream>
#include <set>
using namespace std;

int main() {
  string input;

  cout << "Input: " << endl;
  getline(cin, input); // Read the input sequence as string
  
  set<double> s; // Declare set to store unique numbers
  double sum = 0; // Store the value of the sum of the set
  string num = ""; // Temp variable to build each number

  for (char c : input) {
    if (isdigit(c) || c == '.') { // Build the number (Allow decimals)
      num += c;
    } else if (!num.empty()) { // Check if there is a non-number characters
      s.insert(stod(num)); //　Convert the string to double and insert it (stod => string to double)
      num = ""; // Reset num variable
    }
  }

  // Insert the last number if available
  if (!num.empty()) s.insert(stod(num)); // (stod => string to double)

  // Calculate the sum number of the set
  for (double x : s) {
    sum += x;
  }

  cout << num << endl;

  return 0;
}