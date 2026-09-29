#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

struct LetterCount {
    char letter;
    int count;
};

bool compare(const LetterCount &a, const LetterCount &b) {
    if (a.count != b.count) {
        return a.count > b.count; // Higher frequency comes first
    }
    return a.letter < b.letter;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    cin.ignore(); // Clear newline after reading n

    int freq[26] = {0};

    string line;
    while(n--) {
        getline(cin, line);
        for (char c : line) {
            if (isalpha(c)) {
                freq[toupper(c) - 'A']++;
            }
        }
    }

    // Collect letters with frequency > 0
    vector<LetterCount> result;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            result.push_back({(char)('A' + i), freq[i]});
        }
    }

    // Sort according to problem rules
    sort(result.begin(), result.end(), compare);

    for (const auto &item : result) {
        cout << item.letter << " " << item.count << "\n";
    }

    return 0;
}

