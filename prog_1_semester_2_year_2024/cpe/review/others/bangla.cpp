#include <iostream>
#include <iomanip>
using namespace std;

void bangla(long long n) {
    if (n >= 10000000) { // 1 kuti = 10,000,000
        bangla(n / 10000000);
        cout << " kuti";
        n %= 10000000;
    }

    if (n >= 100000) { // 1 lakh = 100,000
        bangla(n / 100000);
        cout << " lakh";
        n %= 100000;
    }

    if (n >= 1000) { // 1 hajar = 1,000
        bangla(n / 1000);
        cout << " hajar";
        n %= 1000;
    }

    if (n >= 100) { // 1 shata = 100
        bangla(n / 100);
        cout << " shata";
        n %= 100;
    }

    if (n > 0) {
        cout << " " << n;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    int case_num = 1;

    while (cin >> n) {
        // Output case number right-aligned in a 4-char width field
        cout << setw(4) << case_num << ".";

        if (n == 0) {
            cout << " 0";
        } else {
            bangla(n);
        }
        cout << "\n";
        case_num++;
    }

    return 0;
}
