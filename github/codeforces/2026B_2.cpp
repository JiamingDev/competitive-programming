#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define int long long
using pii = pair<int, int>;
using vi = vector<int>;
int solve(vi &a, int n) {
  int ans = 0;
  for (int i = 0; i < n; i += 2)
    ans = max(a[i + 1] - a[i], ans);
  return ans;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    if (n % 2 == 0) {
      cout << solve(a, n) << "\n";
    } else {
      vi tmp = a;
      int ans = 2e18;
      for (int i = 0; i < n; i++) {
        if (find(all(a), a[i] - 1) == a.end()) {
          tmp.push_back(a[i] - 1);
          sort(all(tmp));
          ans = min(ans, solve(tmp, n + 1));
          tmp = a;
        }
        if (find(all(a), a[i] + 1) == a.end()) {
          tmp.push_back(a[i] + 1);
          sort(all(tmp));
          ans = min(ans, solve(tmp, n + 1));
          tmp = a;
        }
      }
      cout << ans << "\n";
    }
  }
  return 0;
}