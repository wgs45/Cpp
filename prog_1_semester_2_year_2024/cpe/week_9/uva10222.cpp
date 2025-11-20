#include <iostream>
#include <string.h>
using namespace std;

int main() {
  char keys[] = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";

  int c;
  while ((c = cin.get()) != EOF) {
    if (c == ' ') {
      putchar(' ');
      continue;
    }

    char lower = c;
    if (c >= 'A' && c <= 'Z')
      lower = c - 'A' + 'a';

    char *pos = strchr(keys, lower);
    if (pos) {
      int idx = pos - keys;
      putchar(keys[idx - 2]);
    } else {
      putchar(c);
    }
  }
  return 0;
}
