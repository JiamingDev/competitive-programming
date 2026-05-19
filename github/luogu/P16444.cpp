#include <bits/stdc++.h>
using namespace std;
#define int long long
struct interval {
  int l, r, c;
  bool operator<(const interval &b) const {
    return r < b.r;
  }
};
signed main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    vector<int> vis(n);
    bool okk = 1;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (i)
        for (int j = 0; j < m; j++)
          if (a[i - 1][j] != a[i][j] && a[i - 1][j] != '?' && a[i][j] != '?') {
            if (vis[i]) {
              okk = false;
              break;
            }
            vis[i] = 1;
          }
    }
    int flag = 0, st;
    vector<interval> v;
    for (int j = 0; j < m; j++) {
      for (int i = 0; i < n; i++)
        if (a[i][j] != '?') {
          if (flag) {
            v.push_back({st, i, j});
            flag = 0;
          }
        } else if (!flag) {
          flag = 1;
          st = i;
        }
      if (flag) {
        v.push_back({st, n, j});
        flag = 0;
      }
    }
    sort(v.begin(), v.end());
    for (auto [l, r, c] : v) {
      int ok = 0;
      if (!l || r == n || a[l - 1][c] == a[r][c]) {
        char tar = '1';
        if (l > 0)
          tar = a[l - 1][c];
        if (r < n)
          tar = a[r][c];
        for (int i = l; i < r; i++)
          a[i][c] = tar;
      } else {
        for (int i = l; i <= r; i++)
          if (!vis[i]) {
            vis[i] = 1;
            ok = i;
            break;
          }
        if (!ok) {
          okk = 0;
          break;
        }
        for (int i = l; i < ok; i++)
          a[i][c] = a[l - 1][c];
        for (int i = ok; i < r; i++)
          a[i][c] = a[r][c];
      }
    }
    if (okk) {
      cout << "Yes\n";
      for (int i = 0; i < n; i++)
        cout << a[i] << "\n";
    } else {
      cout << "No\n";
    }
  }
  return 0;
}