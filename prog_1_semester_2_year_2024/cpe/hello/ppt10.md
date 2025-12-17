# 10008 What’s Cryptanalysis?

```cpp
int main() {
  int count[26] = {0};
  int n;
  cin >> n;
  cin.ignore();


  for (int i = 0; i < n; i++) {
    string line;
    getline(cin, line);

    for (int k = 0; k < (int)line.length(); k++) {
      char c = line[k];
      if (isalpha(c)) {
        c = toupper(c);
        count[c - 'A']++;
      }
    }
  }

  for (int i = 0; i < 26; i++) {
    int maxFreq = 0;
    for (int j = 0; j < 26; j++) {
      if (count[j] > maxFreq) {
        maxFreq = count[j];
      }
    }

    if (maxFreq == 0)
      break;

    for (int j = 0; j < 26; j++) {
      if (count[j] == maxFreq) {
        cout << char(j + 'A') << " " << maxFreq << "\n";
        count[j] = 0;
        break;
      }
    }
  }

  return 0;
}
```

---

# 10038 Jolly Jumpers

```cpp
int main() {
  int n;

  while (cin >> n) {
    int arr[3001];
    int mark[3001] = {0};

    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++) {
      int diff = abs(arr[i] - arr[i + 1]);
      if (diff > 0 && diff < n) {
        mark[diff] = 1;
      }
    }

    int count = 0;
    for (int i = 1; i <= n - 1; i++) {
      if (mark[i] == 1)
        count++;
    }

    if (count == n - 1)
      cout << "Jolly\n";
    else
      cout << "Not jolly\n";
  }

  return 0;
}
```

---

# 10062 Tell me the frequencies

```cpp
int main() {
  char str[1001];
  int first = 1;

  while (fgets(str, sizeof(str), stdin) != NULL) {
    if (!first)
      cout << "\n";
    first = 0;

    int count[128] = {0};
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
      count[(int)str[i]]++;
    }

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
```

---

# 10908 Largest Square

```cpp
int main() {
  int T;
  cin >> T;

  while (T--) {
    int M, N, Q;
    cin >> M >> N >> Q;

    char grid[101][101];
    for (int i = 0; i < M; i++) {
      cin >> grid[i];
    }

    cout << M << " " << N << " " << Q << "\n";

    while (Q--) {
      int r, c;
      cin >> r >> c;

      char center = grid[r][c];
      int size = 1;
      int layer = 1;

      while (true) {
        bool ok = true;

        for (int i = r - layer; i <= r + layer; i++) {
          for (int j = c - layer; j <= c + layer; j++) {

            if (i < 0 || j < 0 || i >= M || j >= N) {
              ok = false;
              break;
            }

            if (grid[i][j] != center) {
              ok = false;
              break;
            }
          }
          if (!ok)
            break;
        }

        if (!ok)
          break;
        size += 2;
        layer++;
      }

      cout << size << "\n";
    }
  }

  return 0;
}
```
