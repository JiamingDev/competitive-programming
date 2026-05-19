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
    vector<int> vis(n + 1), p(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> p[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      int t;
      cin >> t;
      while (!vis[t]) {
        cnt++;
        vis[t] = 1;
        t = p[t];
      }
      cout << cnt << " ";
    }
    cout << "\n";
  }
  return 0;
}