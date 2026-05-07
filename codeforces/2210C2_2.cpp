#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 5e4 + 5;
#define int ll
int a[maxn], b[maxn], c[maxn];
vector<int> pm;
int n;
int solve() {
  a[0] = c[0] = 1, a[n + 1] = c[n + 1] = 1;
  for (int i = 1; i <= n; i++) {
    c[i] = lcm(gcd(a[i - 1], a[i]), gcd(a[i], a[i + 1]));
    if (c[i] > b[i])
      c[i] = a[i];
  }
  vector<vector<int>> dp(n + 1, vector<int>(20, -1e9));
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++)
    for (int x = 0; x < pm.size(); x++)
      for (int k = 0; k < pm.size(); k++) {
        if (x == 0) {
          if (a[i] == c[i])
            dp[i][0] = max(dp[i][0], dp[i - 1][k]);
          else
            dp[i][0] = max(dp[i][0], dp[i - 1][k] + 1);
          continue;
        }
        int val1 = c[i] * pm[x], val2 = c[i - 1] * pm[k];
        if (val1 <= b[i] && gcd(val1, val2) == gcd(a[i], a[i - 1]) && gcd(val1, c[i + 1]) == gcd(a[i], a[i + 1]))
          dp[i][x] = max(dp[i][x], dp[i - 1][k] + (val1 == a[i] ? 0 : 1));
      }
  return *max_element(dp[n].begin(), dp[n].end());
}
signed main() {
  int T;
  cin >> T;
  vector<int> vis(54);
  pm.push_back(1);
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