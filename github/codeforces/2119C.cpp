#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, n) for (int i = 0; i < (n); i++)
signed main() {
  int T;
  cin >> T;
  while (T--) {
    int n, l, r, k;
    cin >> n >> l >> r >> k;
    if (n == 2) {
      cout << -1 << "\n";
      continue;
    }
    if (n & 1)
      cout << l << "\n";
    else if ((int)log2(l) == (int)log2(r))
      cout << -1 << "\n";
    else if (k <= n - 2)
      cout << l << "\n";
    else
      cout << (1ll << (int)log2(l) + 1) << "\n";
  }
  return 0;
}