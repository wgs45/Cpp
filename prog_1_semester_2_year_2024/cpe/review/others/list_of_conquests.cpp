#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    map<string, int> country_count;

    for (int i = 0; i < n; i++) {
        string country, name;

        // Read the first word (Country)
        cin >> country;

        // Read and discard the rest of the line (Woman's name)
        getline(cin, name);

        // Increment the tally for this country
        country_count[country]++;
    }

    // std::map auto iteratres in alphabetical orders
    for (auto pair : country_count) {
        cout << pair.first << " " << pair.second << "\n";
    }

    return 0;
}
