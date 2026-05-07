#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, n) for (int i = 0; i < (n); i++)
signed main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    vector<int> pre(n), suf(n);
    if (a[0] > 0)
      pre[0] = a[0];
    for (int i = 1; i < n; i++) {
      pre[i] = pre[i - 1];
      if (a[i] > 0)
        pre[i] += a[i];
    }
    if (a[n - 1] < 0)
      suf[n - 1] = -a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      suf[i] = suf[i + 1];
      if (a[i] < 0)
        suf[i] += -a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
      ans = max(ans, pre[i] + suf[i]);
    cout << ans << "\n";
  }
  return 0;
}