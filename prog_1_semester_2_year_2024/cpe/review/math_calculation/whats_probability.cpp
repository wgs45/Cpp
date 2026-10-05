#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int s;
    if (cin >> s) {
        while(s--) {
            int n, i;
            double p;
            cin >> n >> p >> i;

            // Corner case: if p is 0, winning is impossible
            if (p == 0.0) {
                cout << "0.0000\n";
                continue;
            }

            double q = 1.0 - p;

            // Formula: (q^(I-1) * p) / (1 - q^N)
            double numerator = pow(q, i - 1) * p;
            double denominator = 1.0 - pow(q, n);
            double ans = numerator / denominator;

            cout << fixed << setprecision(4) << ans << "\n";
        }
    }

    return 0;
}

