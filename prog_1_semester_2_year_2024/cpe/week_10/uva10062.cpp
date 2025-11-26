#include <cstring>
#include <iostream>
using namespace std;

int main() {
  char str[1001];
  int first = 1;

  while (fgets(str, sizeof(str), stdin) != NULL) {
    if (!first)
      cout << "\n";
    first = 0;

    int count[128] = {0};
    int len = strlen(str);

    // Count frequencies
    for (int i = 0; i < len; i++) {
      count[(int)str[i]]++;
    }

    // Print according to rules
    for (int freq = 1; freq <= len; freq++) {
      for (int ascii = 127; ascii >= 32; ascii--) {
        if (count[ascii] == freq) {
          cout << ascii << " " << freq << "\n";
        }
      }
    }
  }
  return 0;
}
