#include <iostream>
#include <vector>
using namespace std;

void solve(int t) {
    char ch1, ch2;
    int n;

    cin >> ch1 >> ch2 >> n;

    vector<vector<long long>> m(n, vector<long long>(n));
    bool is_symmetric = true;

    // Read input & instantly check for negative values
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
            if (m[i][j] < 0) {
                is_symmetric = false;
            }
        }
    }

    // Check center symmetry
    if (is_symmetric) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (m[i][j] != m[n - 1- i][n - 1 - j]) {
                    is_symmetric = false;
                    break;
                }
            }
            if (!is_symmetric) break;
        }
    }

    if (is_symmetric) {
        cout << "Test #" << t << ": Symmetric.\n";
    } else {
        cout << "Test #" << t << ": Non-symmetric.\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        for (int i = 1; i <= t; i++) {
            solve(t);
        }
    }

    return 0;
}

