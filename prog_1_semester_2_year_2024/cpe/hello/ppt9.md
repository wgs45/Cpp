# 10041 Vito's Family

```cpp
int main() {
  int caseNum, r[500], streetNum, temp, median, sum;

  cin >> caseNum;

  while (caseNum--) {
    int i = 0, j = 0;

    cin >> streetNum;

    for (i = 0; i < streetNum; i++) {
      cin >> r[i];
    }

    for (i = 0; i < streetNum; i++) {
      for (j = 0; j < streetNum - i - 1; j++) {
        if (r[j] > r[j + 1]) {
          temp = r[j];
          r[j] = r[j + 1];
          r[j + 1] = temp;
        }
      }
    }
    sum = 0;
    median = r[streetNum / 2];

    for (i = 0; i < streetNum; i++) {
      sum += abs(r[i] - median);
    }
    cout << sum << endl;
  }

  return 0;
}
```

---

# 10190 Divide, But Not Quite Conquer!

```cpp
int main() {
  int m, n, i;

  while (cin >> n >> m) {
    if (m < 2 || n == 0 || n < m) {
      cout << "Boring!" << endl;
      continue;
    }

    int ans[100] = {n};

    for (i = 1;; i++) {
      if (ans[i - 1] == 1)
        break;

      if (ans[i - 1] % m) {
        i = -1;
        break;
      }

      ans[i] = ans[i - 1] / m;
    }

    if (i < 0)
      cout << "Boring!" << endl;
    else {
      cout << ans[0];
      for (n = 1; n < i; n++) {
        cout << " " << ans[n];
      }
      cout << endl;
    }
  }
  return 0;
}
```

---

# 10222 Decode the Mad man

```cpp
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
```

---

# 12019 Doom's Day Algorithm

```cpp
int main() {
  const int dayMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  const char *dayWeek[] = {"Friday",  "Saturday",  "Sunday",  "Monday",
                           "Tuesday", "Wednesday", "Thursday"};

  int T, month, day, i, totalDay;
  cin >> T;

  while (T--) {
    cin >> month >> day;
    totalDay = 0;

    for (i = 0; i < month; i++) {
      totalDay += dayMonth[i];
    }

    totalDay += day;
    cout << dayWeek[totalDay % 7] << endl;
  }
  return 0;
}
```
