#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define int long long
using pii = pair<int, int>;
using vi = vector<int>;
const int mod = 998244353;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  vi dp(3);
  for (char c : s)
    dp[c - 'a'] = (dp[0] + dp[1] + dp[2] + 1) % mod;
  cout << (dp[0] + dp[1] + dp[2]) % mod << "\n";
  return 0;
}