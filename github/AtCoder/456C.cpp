#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define int long long
using pii = pair<int, int>;
using vi = vector<int>;
const int N = 3e5 + 5, mod = 998244353;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vi pw(N);
  pw[0] = 1;
  for (int i = 1; i < N; i++)
    pw[i] = pw[i - 1] * 2 % mod;
  string s;
  cin >> s;
  char last = '\0';
  int cnt = 0, ans = 0;
  for (char c : s) {
    if (c == last) {
      ans = (ans + cnt * (cnt + 1) / 2) % mod;
      last = c;
      cnt = 1;
    } else {
      cnt++;
      last = c;
    }
  }
  ans = (ans + cnt * (cnt + 1) / 2) % mod;
  cout << ans;
  return 0;
}