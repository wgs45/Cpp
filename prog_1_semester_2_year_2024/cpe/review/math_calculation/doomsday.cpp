#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Number of days in each month for 2011 (non-leap year)
    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Days array ordered starting from Saturday (Jan 1, 2011)
    string days[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int m, d;
        cin >> m >> d;

        // Sum up days from previous months
        int total_days = 0;
        for (int i = 1; i < m; ++i) {
            total_days += days_in_month[i];
        }

        // Add days of the target month
        total_days += d;

        // Calculate offset relative to Jan 1st (Saturday = index 0)
        int day_index = (total_days - 1) % 7;

        cout << days[day_index] << "\n";
    }

    return 0;
}

