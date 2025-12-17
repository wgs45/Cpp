# 10409 Die Game

```cpp
int main() {
  int n;
  while (cin >> n && n) {

    int top = 1, bottom = 6;
    int north = 2, south = 5;
    int east = 4, west = 3;

    while (n--) {
      string cmd;
      cin >> cmd;

      if (cmd == "north") {
        int temp = top;
        top = south;
        south = bottom;
        bottom = north;
        north = temp;
      } else if (cmd == "south") {
        int temp = top;
        top = north;
        north = bottom;
        bottom = south;
        south = temp;
      } else if (cmd == "east") {
        int temp = top;
        top = west;
        west = bottom;
        bottom = east;
        east = temp;
      } else if (cmd == "west") {
        int temp = top;
        top = east;
        east = bottom;
        bottom = west;
        west = temp;
      }
    }

    cout << top << "\n";
  }
  return 0;
}
```

---

# 10812 Beat the Spread

```cpp
int main() {
  int n;
  cin >> n;

  while (n--) {
    int s, d;
    cin >> s >> d;

    if (s < d || (s + d) % 2 != 0) {
      cout << "impossible\n";
    } else {
      int a = (s + d) / 2;
      int b = (s - d) / 2;
      cout << a << " " << b << "\n";
    }
  }

  return 0;
}
```

---

# 11063 B2-Sequence

```cpp
int main() {
  int n, caseNum = 1;

  while (cin >> n) {
    vector<int> b(n);
    bool bad = false;

    for (int i = 0; i < n; i++) {
      cin >> b[i];
      if (i > 0 && b[i] <= b[i - 1]) {
        bad = true;       }
    }

    vector<bool> used(20001, false);

    if (!bad) {
      for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
          int sum = b[i] + b[j];
          if (used[sum]) {
            bad = true;
            break;
          }
          used[sum] = true;
        }
        if (bad)
          break;
      }
    }

    cout << "Case #" << caseNum++ << ": ";
    if (!bad)
      cout << "It is a B2-Sequence.\n\n";
    else
      cout << "It is not a B2-Sequence.\n\n";
  }

  return 0;
}
```

---

# 11461 Square Numbers

```cpp
int main() {
  int a, b;
  while (cin >> a >> b && !(a == 0 && b == 0)) {

    int countB = floor(sqrt(b));
    int countA = floor(sqrt(a - 1));

    cout << countB - countA << "\n";
  }
}
```
