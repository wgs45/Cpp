#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Full keyboard layout in row order
    string kb = "1234567890-="
                "qwertyuiop[]\\"
                "asdfghjkl;'"
                "zxcvbnm,./";

    char c;

    // Read input character by character (including spaces and newlines)
    while (cin.get(c)) {
        c = tolower(c);

        // Find position of character in keyboard string
        size_t pos = kb.find(c);

        if (pos != string::npos) {
            // Print character 2 positions to the left
            cout << kb[pos - 2];
        } else {
            // Keep spaces, newlines, etc. unchanged
            cout << c;
        }
    }

    return 0;
}

