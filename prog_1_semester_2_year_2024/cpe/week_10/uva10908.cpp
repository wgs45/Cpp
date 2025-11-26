#include <iostream>
using namespace std;

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

    // Print as required
    cout << M << " " << N << " " << Q << "\n";

    while (Q--) {
      int r, c;
      cin >> r >> c;

      char center = grid[r][c];
      int size = 1;  // at least 1
      int layer = 1; // next layer to check

      // Keep expanding until break
      while (true) {
        bool ok = true;

        // check the new boundary square [r-layer .. r+layer]
        for (int i = r - layer; i <= r + layer; i++) {
          for (int j = c - layer; j <= c + layer; j++) {

            // out of bounds → stop
            if (i < 0 || j < 0 || i >= M || j >= N) {
              ok = false;
              break;
            }

            // different character → stop
            if (grid[i][j] != center) {
              ok = false;
              break;
            }
          }
          if (!ok)
            break;
        }

        if (!ok)
          break;   // can't expand further
        size += 2; // full layer added
        layer++;   // move to next layer
      }

      cout << size << "\n";
    }
  }

  return 0;
}
