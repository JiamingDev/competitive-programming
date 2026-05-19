#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define int long long
using pii = pair<int, int>;
using vi = vector<int>;
const int maxn = 1e5 + 5;
struct city {
  int u, d, st;
};
vi g[maxn];
bool solve() {
  int n, m;
  int w;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    g[i].clear();
  vector<string> s(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  // lambda在这得到w?
  cin >> w;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  vector<vi> color(n + 1, vi(w));
  function<bool(int, int)> dfs = [&](int u, int d) {
    if (color[u][d] == 2)
      return false;
    if (color[u][d] == 1)
      return true;
    color[u][d] = 1;
    int nd = (d + 1) % w;
    if (s[u][nd] == 'o' && dfs(u, nd))
      return true;
    for (int v : g[u])
      if (s[v][nd] == 'o' && dfs(v, nd))
        return true;
    color[u][d] = 2;
    return false;
  };
  for (int i = 1; i <= n; i++)
    if (s[i][0] == 'o' && dfs(i, 0))
      return true;
  return false;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    if (solve())
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}