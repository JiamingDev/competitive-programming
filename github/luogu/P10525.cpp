#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxm = 2e5 + 5, maxn = 1e5 + 5, mod = 998244353;
struct edge {
  int x, y, z;
} e[maxm];
int que[maxm], dy[maxm], out[maxm];
struct graph {
  int32_t tot;
  struct edge {
    int32_t v, ne;
  } e[maxm];
  int32_t h[maxn];
  void add(int32_t u, int32_t v) {
    e[++tot] = {v, h[u]};
    h[u] = tot;
  }
} G[105];
bool vis[105][maxn];
int mx[maxn], ans, pw[maxn];
void dfs(int u, int g) {
  vis[g][u] = 1;
  if (g > mx[u] && u != 1) {
    ans = (ans - pw[u] * mx[u] % mod + mod) % mod;
    ans = (ans + pw[u] * g) % mod;
    mx[u] = g;
  }
  for (int i = G[g].h[u]; i; i = G[g].e[i].ne) {
    int v = G[g].e[i].v;
    if (vis[g][v])
      continue;
    dfs(v, g);
  }
}
signed main() {
  int n, m, q;
  cin >> n >> m >> q;
  pw[1] = 2;
  for (int i = 2; i <= n; i++)
    pw[i] = pw[i - 1] * 2 % mod;
  for (int i = 1; i <= m; i++)
    cin >> e[i].x >> e[i].y >> e[i].z;
  for (int i = 1; i <= q; i++) {
    cin >> que[i] >> dy[i];
    e[que[i]].z -= dy[i];
  }
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= e[i].z; j++) {
      G[j].add(e[i].x, e[i].y);
    }
  for (int i = 1; i <= 100; i++)
    dfs(1, i);
  for (int i = q; i >= 1; i--) {
    out[i] = ans;
    for (int j = e[que[i]].z + 1; j <= e[que[i]].z + dy[i]; j++) {
      G[j].add(e[que[i]].x, e[que[i]].y);
      if (vis[j][e[que[i]].x] && !vis[j][e[que[i]].y])
        dfs(e[que[i]].y, j);
    }
    e[que[i]].z += dy[i];
  }
  for (int i = 1; i <= q; i++)
    cout << out[i] << "\n";
  return 0;
}