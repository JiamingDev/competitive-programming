#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define int long long
void move(int k, int m, int n, int &nr, int &nc) {
  if (k < m - 1)
    nc++;
  else if (k < m + n - 2)
    nr++;
  else if (k < 2 * m + n - 3)
    nc--;
  else
    nr--;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    char tar[] = {'1', '5', '4', '3'};
    int r, c;
    int ans = 0;
    for (int i = 0; i < min(n / 2, m / 2); i++) {
      r = i, c = i;
      for (int j = 0; j < 2 * (m - 2 * i + n - 2 * i - 2);) {
        bool ok = 1;
        int nr = r, nc = c;
        for (int k = j, t = 0; t < 4; t++, k = (k + 1) % (2 * (m - 2 * i + n - 2 * i - 2))) {
          if (a[nr][nc] != tar[t]) {
            ok = 0;
            break;
          }
          move(k, m - 2 * i, n - 2 * i, nr, nc);
        }
        if (ok) {
          ans++;
          r = nr;
          c = nc;
          j += 4;
        } else {
          move(j, m - 2 * i, n - 2 * i, r, c);
          j++;
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}