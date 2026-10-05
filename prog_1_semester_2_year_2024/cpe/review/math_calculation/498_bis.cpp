#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long x;
    // Read x line by line until EOF
    while (cin >> x) {
        string line;
        cin.ignore();
        getline(cin, line);

        stringstream ss(line);
        vector<long long> a;
        long long coeff;
        while (ss >> coeff) {
            a.push_back(coeff);
        }

        long long n = a.size() - 1; // Highest degree
        long long ans = 0;

        // Apply Horner's method for derivative
        for (int i = 0; i < n; i++) {
            ans = ans * x + a[i] * (n - i);
        }

        cout << ans << "\n";
    }

    return 0;
}

