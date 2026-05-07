#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, n) for (int i = 0; i < (n); i++)
bool solve() {
  int n;
  cin >> n;
  int h = 1e9 + 5, maxh = 1e9 + 5;
  bool ok = 1;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    if (t > maxh)
      ok = 0;
    if (t < h) {
      maxh = 2 * t - 1;
      h = t;
    }
  }
  if (!ok)
    return false;
  return true;
}
signed main() {
  int T;
  cin >> T;
  while (T--) {
    if (solve())
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}