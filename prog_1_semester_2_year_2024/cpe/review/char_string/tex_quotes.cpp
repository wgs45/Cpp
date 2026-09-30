#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char c;
    bool first = true;

    while (cin.get(c)) {
        if (c == '"') {
            if (first) {
                cout << "``";
            } else {
                cout << "''";
            }
            first = !first; // Toggle between true and false
        } else {
            cout << c;
        }
    }

    return 0;
}

