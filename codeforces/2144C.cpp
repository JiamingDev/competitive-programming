#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
#define int long long
#define forn(i, n) for (int i = 0; i < (n); i++)
signed main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    forn(i, n) cin >> a[i];
    forn(i, n) cin >> b[i];
    vector<vector<int>> dp(n, vector<int>(2));
    dp[0][0] = dp[0][1] = 1;
    for (int i = 1; i < n; i++)
      if (a[i - 1] <= a[i] && b[i - 1] <= b[i]) {
        if (a[i - 1] <= b[i] && b[i - 1] <= a[i])
          dp[i][0] = dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
        else {
          dp[i][0] = dp[i - 1][0];
          dp[i][1] = dp[i - 1][1];
        }
      } else {
        dp[i][0] = dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
      }
    cout << (dp[n - 1][0] + dp[n - 1][1]) % mod << "\n";
  }
  return 0;
}