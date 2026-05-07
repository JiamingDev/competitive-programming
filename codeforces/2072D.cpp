#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2001;
#define forn(i, n) for (int i = 0; i < (n); i++)
signed main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<vector<int>> up(n + 1, vector<int>(maxn)), low(n + 1, vector<int>(maxn));
    for (int i = 1; i <= n; i++) {
      int &t = a[i];
      cin >> t;
      for (int j = 1; j < maxn; j++) {
        if (t > j)
          up[i][j] = up[i - 1][j] + 1;
        else
          up[i][j] = up[i - 1][j];
        if (t < j)
          low[i][j] = low[i - 1][j] + 1;
        else
          low[i][j] = low[i - 1][j];
      }
    }
    int mx = -1e9;
    int l, r;
    for (int i = 1; i <= n; i++)
      for (int j = i; j <= n; j++) {
        int cnt = low[j][a[i]] - low[i][a[i]], cnt2 = up[j][a[i]] - up[i][a[i]];
        if (cnt - cnt2 > mx) {
          mx = cnt - cnt2;
          l = i, r = j;
        }
      }
    cout << l << " " << r << "\n";
  }
  return 0;
}