#include <cctype>
#include <iostream>
using namespace std;

int main() {
  int count[26] = {0};
  int n;
  cin >> n;
  cin.ignore(); // remove leftover newline

  // Read n lines
  for (int i = 0; i < n; i++) {
    string line;
    getline(cin, line);

    for (int k = 0; k < (int)line.length(); k++) {
      char c = line[k];
      if (isalpha(c)) {
        c = toupper(c);
        count[c - 'A']++;
      }
    }
  }

  // Repeatedly find max and print
  for (int i = 0; i < 26; i++) {
    int maxFreq = 0;

    // Find highest frequency
    for (int j = 0; j < 26; j++) {
      if (count[j] > maxFreq) {
        maxFreq = count[j];
      }
    }

    // If no frequencies left → stop
    if (maxFreq == 0)
      break;

    // Print in alphabetical order
    for (int j = 0; j < 26; j++) {
      if (count[j] == maxFreq) {
        cout << char(j + 'A') << " " << maxFreq << "\n";
        count[j] = 0; // prevent reprinting
        break;
      }
    }
  }

  return 0;
}
