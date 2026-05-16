#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define int long long
using pii = pair<int, int>;
using vi = vector<int>;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    vi mxpre(n + 2);
    for (int i = 2; i <= n; i += 2)
      mxpre[i + 1] = max(mxpre[i - 2], a[i] - a[i - 1]);
    if (n % 2 == 0) {
      cout << mxpre[n + 1] << "\n";
    } else {
      vi mxsuf(n + 3);
      for (int i = n - 2; i >= 1; i -= 2)
        mxsuf[i] = max(mxsuf[i + 2], a[i + 2] - a[i + 1]);
      int ans = 2e18;
      for (int i = 1; i <= n; i += 2)
        ans = min(ans, max(mxpre[i], mxsuf[i]));
      cout << ans << "\n";
    }
  }
  return 0;
}