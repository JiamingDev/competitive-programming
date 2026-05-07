#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, n) for (int i = 0; i < (n); i++)
signed main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m, maxv = 0;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    int r, c;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
        if (a[i][j] > maxv) {
          maxv = a[i][j];
          r = i, c = j;
        }
      }
    vector<int> visr(n), visc(m);
    int r2, c2;
    bool ok = 1;
    forn(i, n) forn(j, m) if (a[i][j] == maxv && i != r && j != c) {
      ok = 0;
      r2 = i, c2 = j;
      break;
    }
    if (ok) {
      cout << maxv - 1 << "\n";
      continue;
    }
    bool vr1 = 0, vc1 = 0, vr2 = 0, vc2 = 0;
    ok = 1;
    forn(i, n) forn(j, m) if (a[i][j] == maxv && !(i == r && j == c) && !(i == r2 && j == c2)) {
      if (i != r && j != c && i != r2 && j != c2) {
        ok = 0;
        break;
      }
      if (i == r)
        vr1 = 1;
      if (j == c)
        vc1 = 1;
      if (i == r2)
        vr2 = 1;
      if (j == c2)
        vc2 = 1;
    }
    if ((vr1 && vc1) || (vr2 && vc2) || (vr1 && vr2) || (vc1 && vc2) || !ok)
      cout << maxv << "\n";
    else
      cout << maxv - 1 << "\n";
  }
  return 0;
}