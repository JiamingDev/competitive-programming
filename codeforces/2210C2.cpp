#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 5e4 + 5;
#define int ll
int a[maxn], b[maxn];
vector<int> pm;
int n;
int solve() {
  a[0] = 1, a[n + 1] = 1;
  vector<int> dp(54), ndp(54);
  for (int i = 1; i <= n; i++) {
    int g1 = gcd(a[i], a[i - 1]), g2 = gcd(a[i], a[i + 1]), lcm = g1 * g2 / gcd(g1, g2);
    if (b[i] < lcm) {
      ndp[1] = dp[1];
      for (int x : pm)
        if (a[i] / g1 % x)
          ndp[1] = max(ndp[1], dp[x]);
    } else if (a[i] != lcm) {
      ndp[1] = dp[1] + 1;
      a[i] = lcm;
      for (int x : pm)
        if (a[i] / g1 % x)
          ndp[1] = max(ndp[1], dp[x] + 1);
    } else {
      ndp[1] = dp[1];
      for (int x : pm)
        if (a[i] / g1 % x)
          ndp[1] = max(ndp[1], dp[x]);
      for (int x : pm) {
        if (a[i] * x > b[i])
          break;
        if ((a[i - 1] / g1) % x) {
          ndp[x] = max(ndp[x], dp[1] + 1);
          for (int y : pm)
            if (y % x && a[i] / g1 % y)
              ndp[x] = max(ndp[x], dp[y] + 1);
        }
      }
    }
    dp = ndp;
    fill(ndp.begin(), ndp.end(), 0);
  }
  int ans = dp[1];
  for (int x : pm)
    ans = max(ans, dp[x]);
  return ans;
}
signed main() {
  int T;
  cin >> T;
  vector<int> vis(54);
  for (int i = 2; i <= 53; i++)
    if (!vis[i]) {
      pm.push_back(i);
      for (int j = i * i; j <= 53; j += i)
        vis[j] = 1;
    }
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    for (int i = 1; i <= n; i++)
      cin >> b[i];
    cout << solve() << "\n";
  }
  return 0;
}