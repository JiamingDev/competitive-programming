#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e6 + 5;
vector<int> g[maxn];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> deg(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    deg[u]++, deg[v]++;
  }
  queue<int> q;
  for (int i = 1; i <= n; i++)
    if (deg[i] == k)
      q.push(i);
  queue<int> nq;
  for (;;) {
    if (q.empty())
      break;
    while (q.size()) {
      int u = q.front();
      q.pop();
      for (int v : g[u])
        if (--deg[v] == k)
          nq.push(v);
      g[u].clear();
      deg[u] = -1;
    }
    while (nq.size()) {
      int u = nq.front();
      nq.pop();
      if (deg[u] == k)
        q.push(u);
    }
  }
  vector<int> vis(n + 1);
  int cnt = 0;
  function<void(int)> dfs = [&](int u) {
    vis[u] = 1;
    for (int v : g[u])
      if (deg[v] >= 0 && !vis[v])
        dfs(v);
  };
  for (int i = 1; i <= n; i++)
    if (deg[i] >= 0 && !vis[i]) {
      cnt++;
      dfs(i);
    }
  cout << cnt << '\n';
  return 0;
}