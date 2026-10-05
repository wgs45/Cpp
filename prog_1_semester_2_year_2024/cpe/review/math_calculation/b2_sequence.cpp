#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int case_num = 1;

    while(cin >> n) {
        vector<int> b(n);
        bool is_b2 = true;

        for (int i = 0; i < n; i++) {
            cin >> b[i];

            // Check rule 1: Must be positive (> 0)
            if (b[i] < 1) {
                is_b2 = false;
            }

            // Check rule 1: Must be strictly increasing
            if (i > 0 && b[i] <= b[i - 1]) {
                is_b2 = false;
            }
        }

        if (is_b2) {
            bool seen[20005] = {false};

            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    int sum = b[i] + b[j];
                    if (seen[sum]) {
                        is_b2 = false; // Duplicate sum found
                        break;
                    }
                    seen[sum] = true;
                }
                if (!is_b2) break;
            }
        }

        cout << "Case # " << case_num++ << ": ";
        if (is_b2) {
            cout << "It is a B2-Sequence.\n\n";
        } else {
            cout << "It is not a B2-Sequence.\n\n";
        }
    }

    return 0;
}

