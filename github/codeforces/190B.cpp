#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define int long long
using pii = pair<int, int>;
using vi = vector<int>;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int n = s.size();
    vi pre(n), suf(n + 1), preo(n), sufo(n);
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
      if (s[i] == '4')
        ans++;
      else if (s[i] == '2')
        pre[i] = suf[i] = 1;
      else
        preo[i] = sufo[i] = 1;
    for (int i = 1; i < n; i++) {
      pre[i] += pre[i - 1];
      preo[i] += preo[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
      suf[i] += suf[i + 1];
      sufo[i] += sufo[i + 1];
    }
    int mn = suf[0];
    for (int i = 0; i < n; i++)
      if (s[i] == '2')
        mn = min(mn, preo[i] + suf[i + 1]);
    cout << ans + mn << "\n";
  }
  return 0;
}