#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, n) for (int i = 0; i < (n); i++)
const int mod = 998244353;
int ksm(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1)
      res = res * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return res;
}
signed main() {
  int T;
  cin >> T;
  int N = 1e5 + 5;
  vector<int> s(N);
  s[0] = 1;
  for (int i = 1; i < N; i++)
    s[i] = s[i - 1] * 2 % mod;
  while (T--) {
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    vector<pair<int, int>> maxp(n), maxq(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
      if (!i || p[i] > maxp[i - 1].first) {
        maxp[i] = {p[i], i};
      } else
        maxp[i] = maxp[i - 1];
    }
    for (int i = 0; i < n; i++) {
      cin >> q[i];
      if (!i || q[i] > maxq[i - 1].first) {
        maxq[i] = {q[i], i};
      } else
        maxq[i] = maxq[i - 1];
    }
    vector<pair<int, int>> r(n);
    for (int i = 0; i < n; i++) {
      if (maxp[i].first > maxq[i].first)
        r[i] = {maxp[i].first, q[i - maxp[i].second]};
      else if (maxp[i].first < maxq[i].first)
        r[i] = {maxq[i].first, p[i - maxq[i].second]};
      else if (q[i - maxp[i].second] > p[i - maxq[i].second]) {
        r[i] = {maxp[i].first, q[i - maxp[i].second]};
      } else
        r[i] = {maxq[i].first, p[i - maxq[i].second]};
    }
    for (auto [a, b] : r) {
      cout << (s[a] + s[b]) % mod << " ";
    }
    cout << "\n";
  }
  return 0;
}