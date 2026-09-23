#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    int r;
    cin >> r;

    vector<int> s(r);
    for (int i = 0; i < r; i++) {
        cin >> s[i];
    }

    // Sort the street numbers
    sort(s.begin(), s.end());

    // Pick the median (Middle house)
    int vito_house = s[r / 2];

    // Sum up all distance
    int total_distance = 0;
    for (int i = 0; i < r; i++) {
        total_distance += abs(s[i] - vito_house);
    }

    cout << total_distance << "\n";
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
