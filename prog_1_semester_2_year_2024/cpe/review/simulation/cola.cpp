#include <iostream>

using namespace std;

int main() {
    // Disables sync between C++ steams (cin/cout) and C streams (scanf/prinf) therefore faster performance I/O
    ios_base::sync_with_stdio(false);

    // Unties cin from cout, only flushes output when finished executing code input
    cin.tie(NULL);

    int n;
    while (cin >> n) {
        cout << n + n / 2 << "\n";
    }

    return 0;
}
