#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 5e5 + 5;
vector<int> g[maxn];
vector<pair<int, int>> query[maxn];
int fa[maxn], vis[maxn], ans[maxn];
int find(int u) {
  return fa[u] == u ? u : fa[u] = find(fa[u]);
}
void tarjan(int u) {
  vis[u] = 1;
  for (int v : g[u])
    if (!vis[v]) {
      tarjan(v);
      fa[v] = u;
    }
  for (auto [v, i] : query[u])
    if (vis[v])
      ans[i] = find(v);
}
signed main() {
  int n, m, s;
  cin >> n >> m >> s;
  for (int i = 1; i <= n; i++)
    fa[i] = i;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    query[u].push_back({v, i});
    query[v].push_back({u, i});
  }
  tarjan(s);
  for (int i = 0; i < m; i++)
    cout << ans[i] << "\n";
  return 0;
}