#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while(cin >> n) {
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        // Checklist to track difference from 1 to n-1
        vector<bool> visited(n, false);
        bool is_jolly = true;

        for (int i = 0; i < n - 1; i++) {
            int diff = abs(nums[i] - nums[i + 1]);

            // Check if difference is valid (between 1 and n-1) and not seen yet
            if (diff >= 1 && diff < n && !visited[diff]) {
                visited[diff] = true; // Mark as seen
            } else {
                is_jolly = false; // Out of range or duplicate difference
                break;
            }
        }

        if (is_jolly) {
            cout << "Jolly\n";
        } else {
            cout << "Not Jolly\n";
        }
    }

    return 0;
}

