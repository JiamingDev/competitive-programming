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
    int n;
    cin >> n;
    vi a(n + 1), b(n + 1), pre(n + 1), nxtp(n + 1);
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    for (int i = 1; i <= n; i++)
      cin >> b[i];
    int ans = 0, last = 0;
    for (int i = 1; i <= n; i++)
      if (a[i] == 1 || b[i] == 1) {
        ans += (i - last) * (i - last - 1) / 2;
        pre[i] = last;
        last = i;
      }
    last = n + 1;
    int first = -1;
    for (int i = n; i >= 1; i--)
      if (a[i] == b[i] && a[i] == 1) {
        nxtp[i] = last;
        last = i;
        first = i;
      }
    if (first != -1) {
      int t = first, cur = 2, last_len = 0;
      vi last_bad(n + 2);
      last_bad[n + 1] = n + 1;
      while (t > 0) {
        int pos = -1;
        for (int i = t; i < nxtp[i]; i++)
          if (a[i] != b[i])
            last_bad[a[i]] = last_bad[b[i]] = i;
        for (int i = t; i < nxtp[i]; i++)
          if ((a[i] == cur && a[i] != b[i]) || (b[i] == cur && a[i] != b[i])) {
            pos = i;
            break;
          } else if (a[i] == b[i] && a[i] == cur)
            cur++;
        int len = last_bad[cur] - t - 1;
        ans += (t - pre[t]) * (len - (t - pre[t]) + 1);
      }
    }
  }
  return 0;
}