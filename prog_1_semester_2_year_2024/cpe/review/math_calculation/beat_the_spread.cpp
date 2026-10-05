#include <iostream>
using namespace std;

void solve() {
    long long s, d;
    cin >> s >> d;

    // Condition 1: Difference cannot exceed sum
    // Condiiton 2: (s + d) must be divisible by 2 to geet integer scores
    if (s < d || (s + d) % 2 != 0) {
        cout << "impossible\n";
    } else {
        long long x = (s + d) / 2;
        long long y = (s - d) / 2;
        cout << x << " " << y << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        while(n--) {
            solve();
        }
    }

    return 0;
}

