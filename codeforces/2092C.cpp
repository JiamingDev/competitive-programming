#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, n) for (int i = 0; i < (n); i++)
signed main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int sum = 0;
    vector<int> vis(2);
    int maxv = 0;
    for (int i = 0; i < n; i++) {
      int t;
      cin >> t;
      maxv = max(maxv, t);
      if (t & 1)
        vis[1]++;
      else
        vis[0]++;
      sum += t;
    }
    if (!vis[0] || !vis[1]) {
      cout << maxv << "\n";
      continue;
    }
    cout << sum - vis[1] + 1 << "\n";
  }
  return 0;
}