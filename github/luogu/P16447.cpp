#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
const int inf = 0x3f3f3f3f;
const ll inf_ll = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353, N = 1e5 + 5;
int a[N], b[N], dp[N], k;
int f(int i, int j) {
  return max(0, k * k - (a[i] - b[j]) * (a[i] - b[j]));
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m >> k;
    fill(dp, dp + m + 1, 0);
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    for (int i = 1; i <= m; i++)
      cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    int l = 1, r = 1;
    for (int i = 1; i <= n; i++) {
      int ol = l;
      while (l <= m && a[i] - b[l] > k)
        l++;
      while (r <= m && b[r] - a[i] <= k)
        r++;
      for (int j = ol; j < r; j++)
        dp[j] = max(dp[j], dp[j - 1]);
      for (int j = r - 1; j >= l; j--)
        dp[j] = max(dp[j], dp[j - 1] + f(i, j));
    }
    int ans = 0;
    for (int i = 1; i <= m; i++)
      ans = max(ans, dp[i]);
    cout << ans << "\n";
  }
  return 0;
}