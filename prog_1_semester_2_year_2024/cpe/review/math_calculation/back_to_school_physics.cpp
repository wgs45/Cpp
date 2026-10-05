#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long v, t;
    while (cin >> v >> t) {
        cout << 2 * v * t << "\n";
    }

    return 0;
}

