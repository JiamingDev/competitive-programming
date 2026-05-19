#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, n) for (int i = 0; i < (n); i++)
signed main() {
  int T;
  cin >> T;
  while (T--) {
    int n, x;
    cin >> n >> x;
    if (n == 1 && x == 0) {
      cout << -1 << "\n";
      continue;
    }
    int cnt = __builtin_popcount(x), lef = n - cnt;
    int ans = 0;
    if (lef > 0) {
      if (lef % 2 == 0)
        ans += lef;
      else if (x == 1)
        ans += lef + 1 + 2;
      else if (x == 0)
        ans += lef + 3;
      else
        ans += lef + 1;
    }
    cout << x + ans << "\n";
  }
  return 0;
}