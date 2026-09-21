#include <iostream>
using namespace std;

int main() {
    long long n;

    while(cin >> n && n != 0) {
        cout << 1 + (n - 1) % 9 << "\n";
    }
}
