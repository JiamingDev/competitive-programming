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
    vector<int> a(n + 1), vis(n + 1), dis(n + 1);
    for (int i = 1; i <= n; i++) {
      dis[i] = dis[i - 1];
      cin >> a[i];
      if (!vis[a[i]]) {
        dis[i]++;
        vis[a[i]] = 1;
      }
    }
    fill(vis.begin(), vis.end(), 0);
    int ans = 0;
    int cnt = 0, end = n;
    for (int i = n; i > 0; i--)
      if (!vis[a[i]]) {
        cnt++;
        vis[a[i]] = 1;
        if (cnt == dis[end]) {
          for (int j = i; j <= end; j++)
            vis[a[j]] = 0;
          ans++;
          end = i - 1;
          cnt = 0;
        }
      }
    cout << ans << "\n";
  }
  return 0;
}