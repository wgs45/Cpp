#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> sentences;
    string line;
    size_t maxLen = 0;

    while (getline(cin, line)) {
        sentences.push_back(line);
        maxLen = max(maxLen, line.length());
    }

    int n = sentences.size();

    // Loop through character columns (from left to right of the original text)
    for (size_t col = 0; col < maxLen; col++) {
        // Loop through sentences in reverse order (from last line to first line)
        for (int row = n - 1; row >= 0; row--) {
            // If the current sentences is long enough, print its character
            if (col < sentences[row].length()) {
                cout << sentences[row][col];
            } else {
                // Otherwise, pad with a space
                cout << ' ';
            }
        }
        cout << "\n";
    }

    return 0;
}

