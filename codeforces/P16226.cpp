#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, n) for (int i = 0; i < (n); i++)
signed main() {
  int T;
  cin >> T;
  while (T--) {
    int l, v, t;
    cin >> l >> v >> t;
    int d = abs(l - 2 * v * t);
    if (d == 0)
      cout << 0 << "\n";
    else if (d & 1)
      cout << (d - 1) / 2 + 1 << "\n";
    else
      cout << d / 2 << "\n";
  }
  return 0;
}