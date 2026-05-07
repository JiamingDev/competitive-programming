#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, n) for (int i = 0; i < (n); i++)
signed main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<int> cntr(n), cntc(m);
    int maxv = 0;
    forn(i, n) forn(j, m) {
      cin >> a[i][j];
      maxv = max(a[i][j], maxv);
    }
    int sum = 0;
    forn(i, n) forn(j, m) if (a[i][j] == maxv) {
      sum++;
      cntr[i]++;
      cntc[j]++;
    }
    bool ok = 0;
    forn(i, n) forn(j, m) if (cntr[i] + cntc[j] - (a[i][j] == maxv) == sum) {
      ok = 1;
      break;
    }
    if (ok)
      maxv--;
    cout << maxv << "\n";
  }
  return 0;
}