#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, n) for (int i = 0; i < (n); i++)
signed main() {
  int T;
  cin >> T;
  while (T--) {
    int k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;
    vector<int> p;
    int res = 1;
    for (;;) {
      if (res > r2)
        break;
      p.push_back(res);
      res *= k;
    }
    int sum = 0;
    for (int x : p) {
      int l = max(l1, (l2 - 1 + x) / x), r = min(r1, r2 / x);
      if (r >= l)
        sum += r - l + 1;
    }
    cout << sum << "\n";
  }
  return 0;
}