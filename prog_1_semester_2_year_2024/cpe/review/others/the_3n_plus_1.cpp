#include <iostream>
#include <algorithm>
using namespace std;

int getCycleLength(long long n) {
    int length = 1; // Starts at 1 because we cpimt the starting number itself

    while (n != 1) {
        if (n % 2 != 0) {
            n = 3 * n + 1; // Odd number
        } else {
            n /= 2; // Even number
        }
        length++;
    }

    return length;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;

    while (cin >> i >> j) {
        // Find the actual range bounds (start, end)
        int start = min(i, j);
        int end = max(i, j);

        int max_cycle = 0;

        // Loop through every number in the range adn find the max cycle
        for (int k = start; k <= end; k++) {
            int current_cycle = getCycleLength(k);
            max_cycle = max(max_cycle, current_cycle);
        }

        cout << i << " " << j << " " << max_cycle << "\n";
    }

    return 0;
}
