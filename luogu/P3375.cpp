#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 5e5 + 5;
vector<int> g[maxn];
int fa[maxn], top[maxn], son[maxn], sz[maxn], dep[maxn];
void dfs1(int u, int f) {
  fa[u] = f;
  sz[u] = 1;
  dep[u] = dep[f] + 1;
  for (int v : g[u])
    if (v != f) {
      dfs1(v, u);
      sz[u] += sz[v];
      if (sz[son[u]] < sz[v])
        son[u] = v;
    }
}
void dfs2(int u, int t) {
  top[u] = t;
  if (!son[u])
    return;
  dfs2(son[u], t);
  for (int v : g[u])
    if (v != son[u] && v != fa[u])
      dfs2(v, v);
}
int lca(int u, int v) {
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]])
      swap(u, v);
    u = fa[top[u]];
  }
  return dep[u] < dep[v] ? u : v;
}
signed main() {
  int n, m, s;
  cin >> n >> m >> s;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs1(s, 0);
  dfs2(s, s);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    cout << lca(u, v) << "\n";
  }
  return 0;
}