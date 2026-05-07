#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
signed main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), sum(n), diff(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    sum[1] = a[0];
    for (int i = 2; i < n; i++)
      sum[i] = sum[i - 1] + abs(a[i - 1]);
    for (int i = n - 2; i >= 0; i--)
      diff[i] = diff[i + 1] - a[i + 1];
    int ans = -1e15;
    for (int i = 0; i < n; i++)
      ans = max(ans, sum[i] + diff[i]);
    cout << ans << "\n";
  }
  return 0;
}