#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 5;
int col[maxn], son[maxn], sz[maxn], cnt[maxn], maxc, sum, flag, ans[maxn];
vector<int> g[maxn];
void dfs(int u, int f) {
  sz[u] = 1;
  for (int v : g[u])
    if (v != f) {
      dfs(v, u);
      sz[u] += sz[v];
      if (sz[son[u]] < sz[v])
        son[u] = v;
    }
}
void count(int u, int f, int val) {
  cnt[col[u]] += val;
  if (cnt[col[u]] > maxc) {
    maxc = cnt[col[u]];
    sum = col[u];
  } else if (cnt[col[u]] == maxc)
    sum += col[u];
  for (int v : g[u])
    if (v != f && v != flag)
      count(v, u, val);
}
void dfs2(int u, int f, bool keep) {
  for (int v : g[u])
    if (v != f && v != son[u])
      dfs2(v, u, false);
  if (son[u]) {
    dfs2(son[u], u, true);
    flag = son[u];
  }
  count(u, f, 1);
  ans[u] = sum;
  flag = 0;
  if (!keep) {
    count(u, f, -1);
    sum = maxc = 0;
  }
}
signed main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> col[i];
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  dfs2(1, 0, 1);
  for (int i = 1; i <= n; i++)
    cout << ans[i] << " ";
  return 0;
}