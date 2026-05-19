#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 5;
ll q[maxn], r[maxn];
ll n, k;
bool check(int m) {
  for (int i = 0; i < m; i++)
    if (q[i] * (r[m - i - 1] + 1) + r[m - 1 - i] > k)
      return false;
  return true;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    for (int i = 0; i < n; i++)
      cin >> q[i];
    for (int i = 0; i < n; i++)
      cin >> r[i];
    sort(q, q + n);
    sort(r, r + n);
    ll l = 0, r = n;
    int ans = -1;
    while (l <= r) {
      int mid = l + r >> 1;
      if (check(mid)) {
        l = mid + 1;
        ans = mid;
      } else
        r = mid - 1;
    }
    cout << ans << "\n";
  }
  return 0;
}