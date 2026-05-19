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
    int ans = 0;
    for (int i = 0; i < min(n / 2, m / 2); i++) {
      int lef = i, righ = m - i - 1, top = i, bot = n - i - 1;
      string s;
      for (int j = lef; j < righ; j++)
        s += a[i][j];
      for (int j = top; j < bot; j++)
        s += a[j][righ];
      for (int j = righ; j > lef; j--)
        s += a[bot][j];
      for (int j = bot; j > top; j--)
        s += a[j][lef];
      s += s.substr(0, 3);
      for (int i = 0; i < s.size() - 3; i++)
        if (s.substr(i, 4) == "1543")
          ans++;
    }
    cout << ans << "\n";
  }
  return 0;
}