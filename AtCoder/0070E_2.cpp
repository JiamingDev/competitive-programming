#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define int long long
using pii = pair<int, int>;
using vi = vector<int>;
const int maxn = 5e4 + 5;
struct edge {
  int v, c, ne;
} e[maxn * 2];
int h[maxn], pos[maxn], dist[20][20];
int tot = 1;
void add(int u, int v, int c) {
  e[++tot] = {v, c, h[u]};
  h[u] = tot;
  e[++tot] = {u, c, h[v]};
  h[v] = tot;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vi tar(k + 1);
  for (int i = 1; i <= k; i++) {
    cin >> tar[i];
  }
  tar[0] = 1;
  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    add(u, v, c);
  }
  for (int m = 0; m < tar.size(); m++) {
    int st = tar[m];
    vi d(n + 1, 1e18), vis(n + 1);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, st});
    d[st] = 0;
    while (pq.size()) {
      auto [t, u] = pq.top();
      pq.pop();
      if (vis[u])
        continue;
      vis[u] = 1;
      for (int i = h[u]; i; i = e[i].ne) {
        int v = e[i].v, c = e[i].c;
        if (d[v] > d[u] + c) {
          d[v] = d[u] + c;
          pq.push({d[v], v});
        }
      }
    }
    for (int i = 0; i < k + 1; i++)
      dist[m][i] = d[tar[i]];
  }
  vector<vi> dp(1 << k + 1, vi(k + 1, 1e18)), vis(1 << k + 1, vi(k + 1, 1e18));
  queue<pii> q;
  dp[1][0] = 0;
  for (int i = 1; i < 1 << k + 1; i++)
    for (int u = 0; u < k + 1; u++)
      for (int v = 0; v < k + 1; v++) {
        dp[i | 1 << v][v] = min(dp[i | 1 << v][v], dp[i][u] + dist[u][v]);
      }
  cout << dp[(1 << k + 1) - 1][0];
  return 0;
}