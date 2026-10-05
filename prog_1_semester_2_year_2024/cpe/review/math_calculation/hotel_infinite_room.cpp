#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long s, d;

    while (cin >> s >> d) {
        // Keep subtracting group sizes until we reach or pass day D
        while (d > 0) {
            d -= s; // Group os size 's' satys for 's' days
            if (d <= 0) {
                cout << s << "\n";
                break;
            }
            s++; // Next group has 1 more number
        }
    }

    return 0;
}

