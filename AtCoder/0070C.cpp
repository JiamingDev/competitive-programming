#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define int long long
using pii = pair<int, int>;
using vi = vector<int>;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, y, m;
  cin >> n >> y >> m;
  int ne = m + 1, ny = y;
  if (m == 12) {
    ne = 1;
    ny++;
  }
  int c1 = 0, c2 = 0;
  for (int i = 0; i < n; i++) {
    int t1, t2, p1, q1, c;
    cin >> t1 >> t2 >> p1 >> q1 >> c;
    if (q1 == ne && p1 == ny)
      c2 += c;
    if (q1 == m && p1 == y)
      c1 += c;
  }
  cout << c1 << " " << c2 << "\n";
  return 0;
}