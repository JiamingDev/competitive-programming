#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, n) for (int i = 0; i < (n); i++)
signed main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m, k;
    cin >> n >> m >> k;
    int l = 1, r = m;
    int ans = -1;
    while (l <= r) {
      int mid = l + r >> 1;
      if (n * (m / (mid + 1) * mid + m % (mid + 1)) < k)
        l = mid + 1;
      else {
        ans = mid;
        r = mid - 1;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}