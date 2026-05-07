#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, n) for (int i = 0; i < (n); i++)
signed main() {
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> cost;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int t;
      cin >> t;
      for (int i = 0; i < 63; i++)
        if (!(1ll << i & t))
          cost.push_back(1ll << i);
        else
          ans++;
    }
    sort(cost.begin(), cost.end());
    for (int i = 0; i < cost.size(); i++) {
      if (k - cost[i] < 0)
        break;
      k -= cost[i];
      ans++;
    }
    cout << ans << "\n";
  }
  return 0;
}