#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
const int inf = 0x3f3f3f3f;
const ll inf_ll = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const int maxn = 5e5 + 5;
struct edge {
  int v, w, ne;
} e[2 * maxn];
int tot = 1, h[maxn], dep[maxn], bz[maxn][20], xo[maxn], txo[maxn], mx[maxn], zs[maxn], t, flag[maxn];
vi fz[maxn], seq;
void add(int u, int v, int w) {
  e[++tot] = {v, w, h[u]};
  h[u] = tot;
  e[++tot] = {u, w, h[v]};
  h[v] = tot;
}
void dfs1(int u, int f) {
  dep[u] = dep[f] + 1;
  bz[u][0] = f;
  for (int i = 1; i < 20; i++)
    bz[u][i] = bz[bz[u][i - 1]][i - 1];
  for (int i = h[u]; i; i = e[i].ne) {
    int v = e[i].v;
    if (v == f)
      continue;
    xo[v] = xo[u] ^ e[i].w;
    dfs1(v, u);
  }
}
int lca(int u, int v) {
  if (dep[u] < dep[v])
    swap(u, v);
  for (int i = 19; i >= 0; i--)
    if (dep[bz[u][i]] >= dep[v])
      u = bz[u][i];
  if (u == v)
    return u;
  for (int i = 19; i >= 0; i--)
    if (bz[u][i] != bz[v][i]) {
      u = bz[u][i];
      v = bz[v][i];
    }
  return bz[u][0];
}
void dfs2(int u, int f) {
  if (u == t) {
    flag[u] = 1;
    return;
  }
  for (int i = h[u]; i; i = e[i].ne) {
    int v = e[i].v;
    if (v != f) {
      dfs2(v, u);
      if (flag[v])
        flag[u] = 1;
    }
  }
}
void dfs3(int u, int f) {
  seq.pb(u);
  for (int i = h[u]; i; i = e[i].ne) {
    int v = e[i].v;
    if (v != f && !flag[v]) {
      dfs3(v, u);
      seq.pb(u);
    }
  }
  for (int i = h[u]; i; i = e[i].ne) {
    int v = e[i].v;
    if (v != f && flag[v]) {
      dfs3(v, u);
    }
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    add(u, v, w);
  }
  dfs1(1, 0);
  for (int i = 1; i <= n; i++)
    txo[i] = xo[i];
  sort(txo + 1, txo + n + 1);
  int cnt = unique(txo + 1, txo + n + 1) - txo - 1;
  for (int i = 1; i <= n; i++) {
    int x = lower_bound(txo + 1, txo + cnt + 1, xo[i]) - txo;
    fz[x].pb(i);
    if (dep[i] > mx[x]) {
      mx[x] = dep[i];
      zs[x] = i;
    }
  }
  int mxl = -1;
  int s = 0;
  for (int x = 1; x <= cnt; x++) {
    int u = zs[x];
    for (int v : fz[x]) {
      int tmp = dep[v] + dep[u] - 2 * dep[lca(u, v)];
      if (tmp > mxl) {
        mxl = tmp;
        s = u;
        t = v;
      }
    }
  }
  dfs2(s, 0);
  dfs3(s, 0);
  cout << seq.size() << "\n";
  for (int x : seq)
    cout << x << " ";
  return 0;
}