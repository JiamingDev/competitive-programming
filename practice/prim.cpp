#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct edge {
  int v, w;
};
int d[5005], vis[5005];
int n, m, ans, cnt;
vector<edge> g[5005];
bool prim() {
  memset(d, 0x3f, sizeof(d));
  d[1] = 0;
  priority_queue<pair<int, int>> pq;
  pq.push({0, 1});
  while (pq.size()) {
    int u = pq.top().second;
    pq.pop();
    if (vis[u])
      continue;
    vis[u] = 1;
    cnt++;
    ans += d[u];
    for (auto ed : g[u]) {
      int v = ed.v, w = ed.w;
      if (!vis[v] && d[v] > w) {
        d[v] = w;
        pq.push({-w, v});
      }
    }
  }
  return cnt == n;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  if (prim())
    cout << ans << "\n";
  else
    cout << "orz\n";
  return 0;
}