#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, n) for (int i = 0; i < (n); i++)
signed main() {
  int n, m, x;
  cin >> n >> m >> x;
  vector<int> a(m), b(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
  }
  vector<int> cost(n + 1, 1e18);
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < m; j++)
      cost[i] = min(cost[i], i * a[j] + i * (i - 1) / 2 * b[j]);
  vector<int> dp(n + 1, 1e18);
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    dp[i] = cost[i];
    for (int j = 1; j < i; j++)
      dp[i] = min(dp[i], dp[j] + x + cost[i - j]);
  }
  cout << dp[n] << "\n";
  return 0;
}