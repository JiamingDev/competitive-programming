#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lc (p << 1)
#define rc (p << 1 | 1)
const int maxn = 1e5 + 5;
struct node {
  int l, r, sum, add;
} tr[4 * maxn];
vector<int> g[maxn];
int mod, w[maxn], fa[maxn], dep[maxn], sz[maxn], son[maxn], top[maxn], id[maxn], cnt, nw[maxn];
void dfs1(int u, int f) {
  dep[u] = dep[f] + 1;
  fa[u] = f;
  sz[u] = 1;
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
  id[u] = ++cnt;
  nw[cnt] = w[u];
  if (!son[u])
    return;
  dfs2(son[u], t);
  for (int v : g[u])
    if (v != fa[u] && v != son[u])
      dfs2(v, v);
}
void pushup(int p) {
  tr[p].sum = (tr[lc].sum + tr[rc].sum) % mod;
}
void build(int p, int x, int y) {
  tr[p] = {x, y, nw[x] % mod};
  if (x == y)
    return;
  int m = x + y >> 1;
  build(lc, x, m);
  build(rc, m + 1, y);
  pushup(p);
}
void pushdown(int p) {
  int &k = tr[p].add;
  if (k) {
    auto &l = tr[lc], &r = tr[rc];
    l.sum = (l.sum + k * (l.r - l.l + 1) % mod) % mod;
    r.sum = (r.sum + k * (r.r - r.l + 1) % mod) % mod;
    l.add = (l.add + k) % mod;
    r.add = (r.add + k) % mod;
    k = 0;
  }
}
void update(int p, int x, int y, int k) {
  int l = tr[p].l, r = tr[p].r;
  if (x <= l && r <= y) {
    tr[p].sum = (tr[p].sum + k * (r - l + 1)) % mod;
    tr[p].add = (tr[p].add + k) % mod;
    return;
  }
  pushdown(p);
  int m = l + r >> 1;
  if (x <= m)
    update(lc, x, y, k);
  if (y > m)
    update(rc, x, y, k);
  pushup(p);
}
int query(int p, int x, int y) {
  int l = tr[p].l, r = tr[p].r, sum = 0;
  if (x <= l && y >= r)
    return tr[p].sum;
  pushdown(p);
  int m = l + r >> 1;
  if (x <= m)
    sum = (query(lc, x, y) + sum) % mod;
  if (y > m)
    sum = (query(rc, x, y) + sum) % mod;
  return sum;
}
void update_path(int x, int y, int k) {
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]])
      swap(x, y);
    update(1, id[top[x]], id[x], k);
    x = fa[top[x]];
  }
  if (dep[x] < dep[y])
    swap(x, y);
  update(1, id[y], id[x], k);
}
int query_path(int u, int v) {
  int sum = 0;
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]])
      swap(u, v);
    sum = (sum + query(1, id[top[u]], id[u])) % mod;
    u = fa[top[u]];
  }
  if (dep[u] < dep[v])
    swap(u, v);
  return (query(1, id[v], id[u]) + sum) % mod;
}
signed main() {
  int n, m, s;
  cin >> n >> m >> s >> mod;
  for (int i = 1; i <= n; i++)
    cin >> w[i];
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs1(s, 0);
  dfs2(s, s);
  build(1, 1, n);
  for (int i = 0; i < m; i++) {
    int op, x, y, z;
    cin >> op;
    if (op == 1) {
      cin >> x >> y >> z;
      update_path(x, y, z);
    } else if (op == 2) {
      cin >> x >> y;
      cout << query_path(x, y) << "\n";
    } else if (op == 3) {
      cin >> x >> z;
      update(1, id[x], id[x] + sz[x] - 1, z);
    } else {
      cin >> x;
      cout << query(1, id[x], id[x] + sz[x] - 1) << "\n";
    }
  }
  return 0;
}