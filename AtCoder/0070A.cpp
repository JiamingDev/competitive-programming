#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define int long long
using pii = pair<int, int>;
using vi = vector<int>;
const int mod = 1e9 + 7;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  s = " " + s;
  int cnt = 0;
  vi dp(n + 1);
  dp[0] = 1;
  for (int i = 1; i <= n; i++)
    if (s[i] == '.') {
      for (int j = i - 1; j >= max(i - 3, 0ll); j--)
        if (s[j] != '#')
          dp[i] = (dp[i] + dp[j]) % mod;
    }
  cout << dp[n];
  return 0;
}