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
    string s;
    cin >> s;
    int lef = 0;
    for (int i = x - 2; i >= 0; i--, lef++)
      if (s[i] == '#')
        break;
    int righ = 0;
    for (int i = x; i < n; i++, righ++)
      if (s[i] == '#')
        break;
    if (x - lef > n - x + 1 - righ)
      cout << min(n - x + 1, x - lef) << "\n";
    else
      cout << min(x, n - x + 1 - righ) << "\n";
  }
  return 0;
}