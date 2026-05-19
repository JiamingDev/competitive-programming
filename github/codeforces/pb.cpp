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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    sort(a.begin(), a.end());
    vector<int> v1, v2;
    for (int i = 0; i < n - 1; i++)
      if (v1.size() && v1.back() == a[i])
        v2.push_back(a[i]);
      else
        v1.push_back(a[i]);
    int t = 0;
    a[0] = a[n - 1];
    for (int x : v1)
      a[++t] = x;
    for (int x : v2)
      a[++t] = x;
    int mx = a[0], mw = 0, ans = 0;
    vector<int> vis(n + 1);
    for (int i = 0; i < n; i++) {
      if (a[i] < n)
        vis[a[i]]++;
      while (vis[mw])
        mw++;
      ans += mx + mw;
    }
    cout << ans << "\n";
  }
  return 0;
}