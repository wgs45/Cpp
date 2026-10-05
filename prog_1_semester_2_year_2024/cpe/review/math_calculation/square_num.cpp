#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    while (cin >> a >> b && (a != 0 || b != 0)) {
        int start = sqrt(a);
        if (start * start < a) {
            start++; // Round up if a is not a perfect square
        }
        int end = sqrt(b); // Automatically rounded down

        int count = end - start + 1;
        cout << count << "\n";
    }

    return 0;
}

