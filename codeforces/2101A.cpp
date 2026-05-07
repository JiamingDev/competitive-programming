#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, n) for (int i = 0; i < (n); i++)
signed main() {
  int T;
  cin >> T;
  int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
  while (T--) {
    int n;
    cin >> n;
    int x = n / 2, y = n / 2;
    if (n % 2 == 0)
      x--, y--;
    int step = 1;
    vector<vector<int>> a(n, vector<int>(n));
    int cnt = 1;
    int dir = 0;
    while (cnt < n * n) {
      for (int j = 0; j < step; j++) {
        if (cnt == n * n)
          break;
        x += dx[dir % 4];
        y += dy[dir % 4];
        a[x][y] = cnt++;
      }
      dir++;
      if ((dir) % 2 == 0)
        step++;
    }
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        cout << a[i][j] << " \n"[j == n - 1];
  }
  return 0;
}