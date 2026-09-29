#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    // Read pairs of lines until End-Of-File (EOF)
    while (getline(cin, a) && getline(cin, b)) {
        int countA[26] = {0};
        int countB[26] = {0};

        // Count frequency of each letter in string a
        for (char c : a) {
            if (c >= 'a' && c <= 'z') {
                countA[c - 'a']++;
            }
        }

        // Count frequency of each letter in string b
        for (char c : b) {
            if (c >= 'a' && c <= 'z') {
                countB[c - 'a']++;
            }
        }

        // Print common characters in alphabetical order ('a' to 'z')
        for (int i = 0; i < 26; i++) {
            int common = min(countA[i], countB[i]);
            for (int k = 0; k < common; k++) {
                cout << (char)('a' + i);
            }
        }
        cout << "\n";
    }

    return 0;
}

