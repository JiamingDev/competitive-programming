#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, h, k;
    cin >> n >> h >> k;
    vector<ll> sum(n + 1), maxv(n + 2, 0), a(n + 1), minv(n + 1, 1e9);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      sum[i] = sum[i - 1] + a[i];
      minv[i] = min(a[i], minv[i - 1]);
    }
    for (int i = n; i > 0; i--)
      maxv[i] = max(maxv[i + 1], a[i]);
    ll cnt = h / sum[n], sumt = cnt * n + (cnt - 1) * k;
    h -= cnt * sum[n];
    if (h == 0) {
      cout << sumt << "\n";
      continue;
    }
    sumt += k;
    int l = 1, r = n;
    while (l < r) {
      int mid = (r + l) / 2;
      if (sum[mid] + max(0ll, maxv[mid + 1] - minv[mid]) >= h)
        r = mid;
      else
        l = mid + 1;
    }
    sumt += l;
    cout << sumt << "\n";
  }
  return 0;
}