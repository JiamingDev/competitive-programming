#include <bits/stdc++.h>
using namespace std;
#define int long long
int maxd = 5000;
signed main() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  int sum = 0, pos = 1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  int tsum = 0;
  while (pos <= n && tsum + a[pos] < sum / 2) {
    tsum += a[pos];
    pos++;
  }
  vector<vector<int>> dp(2, vector<int>(2 * maxd + 1));
  int t = 0;
  dp[0][tsum - sum / 2 + maxd] = pos;
  for (int i = pos; i <= n; i++) {
    for (int j = 0; j <= 2 * maxd; j++)
      dp[t ^ 1][j] = dp[t][j];
    for (int j = 0; j <= maxd; j++)
      dp[t ^ 1][j + a[i]] = max(dp[t ^ 1][j + a[i]], dp[t][j]);
    for (int j = 2 * maxd; j >= maxd + 1; j--) {
      for (int k = dp[t][j]; k < dp[t ^ 1][j]; k++)
        dp[t ^ 1][j - a[k]] = max(dp[t ^ 1][j - a[k]], k);
    }
    t ^= 1;
  }
  int ans = 1e9;
  for (int j = 0; j <= 2 * maxd; j++)
    if (dp[t][j]) {
      int w = sum / 2 + j - maxd;
      ans = min(ans, abs(sum - w - w));
    }
  cout << ans << '\n';
  return 0;
}