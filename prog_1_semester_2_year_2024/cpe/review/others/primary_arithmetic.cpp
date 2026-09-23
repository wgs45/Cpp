#include <iostream>
using namespace std;

void solve(long long a, long long b) {
    int carry = 0, carry_count = 0;

    // Keep loop going as long as there are digits left or a carry to process
    while(a > 0 || b > 0) {
        int digit_a = a % 10;
        int digit_b = b % 10;

        int sum = digit_a + digit_b + carry;

        if (sum >= 10) {
            carry = 1;
            carry_count++;
        } else {
            carry = 0;
        }

        // Chop off the last digit
        a /= 10;
        b /= 10;
    }

    if (carry_count == 0) {
        cout << "No carry operation.\n";
    } else if (carry_count == 1) {
        cout << "1 carry operation.\n";
    } else {
        cout << carry_count << " carry operations.\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;

    while(cin >> a >> b && (a != 0 || b != 0)) {
        solve(a, b);
    }

    return 0;
}
