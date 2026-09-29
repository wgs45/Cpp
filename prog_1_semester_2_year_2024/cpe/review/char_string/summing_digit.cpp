#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while(cin >> n && n != 0) {
        // Keep summing digits until n becomes a singel digit (0-9)
        while(n >= 10) {
            int sum = 0;
            while(n > 0) {
                sum += n % 10; // Take last digit
                n /= 10; // Shrink number
            }
            n = sum;
        }
        cout << n << "\n";
    }

    return 0;
}

