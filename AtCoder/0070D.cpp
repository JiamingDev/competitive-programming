#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define int long long
using pii = pair<int, int>;
using vi = vector<int>;
int flag[1505][1505], a[1505][1505];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      cin >> a[i][j];
  for (int i = 0; i < q; i++) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    flag[r1][c1] ^= 1;
    flag[r1][c2 + 1] ^= 1;
    flag[r2 + 1][c1] ^= 1;
    flag[r2 + 1][c2 + 1] ^= 1;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      flag[i][j] ^= flag[i - 1][j] ^ flag[i][j - 1] ^ flag[i - 1][j - 1];
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (flag[i][j] & 1)
        ans += 2 * a[i][j];
      else
        ans += a[i][j];
  cout << ans;
  return 0;
}