#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define int long long
using pii = pair<int, int>;
using vi = vector<int>;
bool solve() {
  int n, m, q;
  cin >> n >> m >> q;
  vi a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vi b;
  vi vis(n + 1);
  for (int i = 0; i < m; i++) {
    int t;
    cin >> t;
    if (!vis[t]) {
      b.push_back(t);
      vis[t] = 1;
    }
  }
  for (int i = 0; i < b.size(); i++)
    if (b[i] != a[i])
      return false;
  return true;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    if (solve())
      cout << "YA\n";
    else
      cout << "TIDAK\n";
  }
  return 0;
}