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
    vector<int> cnt(n * m + 1);
    vector<vector<int>> a(n + 2, vector<int>(m + 2));
    int diff = 1;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        cin >> a[i][j];
    int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        for (int k = 0; k < 4; k++)
          if (a[i + di[k]][j + dj[k]] == a[i][j]) {
            cnt[a[i][j]] = 2;
            diff = 2;
          } else
            cnt[a[i][j]] = max(cnt[a[i][j]], 1ll);
      }
    int sum = 0;
    for (int i = 1; i <= n * m; i++)
      sum += cnt[i];
    cout << sum - diff << "\n";
  }
  return 0;
}