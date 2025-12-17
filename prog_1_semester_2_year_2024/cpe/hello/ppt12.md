# 10019 Funny Encryption Method

```cpp
int main() {

  int hexOnes[16] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};

  int T;
  cin >> T;

  while (T--) {
    int n;
    cin >> n;

    int x = n;
    int b1 = 0;

    while (x > 0) {
      b1 += x % 2;
      x /= 2;
    }

    int y = n;
    int b2 = 0;

    while (y > 0) {
      int digit = y % 10;
      b2 += hexOnes[digit];
      y /= 10;
    }
    cout << b1 << " " << b2 << endl;
  }

  return 0;
}
```

---

# 10235 Simply Emirp

```cpp
bool isPrime(int n) {
  if (n < 3)
    return false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0)
      return false;
  }
  return true;
}

int reverseNum(int n) {
  int r = 0;
  while (n > 0) {
    r = r * 10 + n % 10;
    n /= 10;
  }
  return r;
}

int main() {
  int n;

  while (cin >> n) {
    if (!isPrime(n)) {
      cout << n << " is not prime." << endl;
      continue;
    }

    int rev = reverseNum(n);

    if (rev != n && isPrime(rev)) {
      cout << n << " is emrip." << endl;
    } else {
      cout << n << " is prime." << endl;
    }
  }

  return 0;
}
```

---

# 11417 GCD

```cpp
int gcd(int a, int b) {
  while (b != 0) {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int main() {
  int N;
  while (cin >> N && N != 0) {
    int sum = 0;
    for (int i = 1; i < N; i++) {
      for (int j = i + 1; j <= N; j++) {
        sum += gcd(i, j);
      }
    }
    cout << sum << "\n";
  }
  return 0;
}
```

---

# 948 Fibonaccimal Base

```cpp
int main() {
  vector<int> fib(40);
  fib[0] = 0;
  fib[1] = 1;

  for (int i = 2; i < 40; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }

  int T;
  cin >> T;

  while (T--) {
    int n;
    cin >> n;

    cout << n << " = ";

    int num = n;
    bool started = false;

    for (int i = 39; i >= 2; i--) {
      if (num >= fib[i]) {
        num -= fib[i];
        cout << "1";
        started = true;
      } else if (started) {
        cout << "0";
      }
    }
    cout << " (fib)" << endl;
  }

  return 0;
}
```
