#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, n) for (int i = 0; i < (n); i++)
bool solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++)
    cin >> b[i];
  sort(b.begin(), b.end());
  int lim = -1e9;
  for (int i = 0; i < n; i++) {
    int l = 0, r = m - 1, ans = 1e9;
    while (l <= r) {
      int mid = l + r >> 1;
      if (b[mid] - a[i] >= lim) {
        ans = b[mid] - a[i];
        r = mid - 1;
      } else
        l = mid + 1;
    }
    if (ans == 1e9 && a[i] < lim)
      return false;
    if (a[i] >= lim)
      lim = min(a[i], ans);
    else
      lim = ans;
  }
  return true;
}
signed main() {
  int T;
  cin >> T;
  while (T--) {
    if (solve())
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}