#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct edge {
  int v, c, ne;
} e[305 * 305 * 2];
int h[305], s, t, tot = 1, d[305], cur[305];
void add(int u, int v, int c) {
  e[++tot] = {v, c, h[u]};
  h[u] = tot;
  e[++tot] = {u, c, h[v]};
  h[v] = tot;
}
bool bfs() {
  memset(d, 0, sizeof(d));
  queue<int> q;
  d[s] = 1;
  q.push(s);
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int i = h[u]; i; i = e[i].ne) {
      int v = e[i].v;
      if (d[v] == 0 && e[i].c) {
        d[v] = d[u] + 1;
        q.push(v);
        if (v == t)
          return true;
      }
    }
  }
  return false;
}
int dfs(int u, int mf) {
  if (u == t)
    return mf;
  int sum = 0;
  for (int &i = cur[u]; i; i = e[i].ne) {
    int v = e[i].v;
    if (d[v] == d[u] + 1 && e[i].c) {
      int f = dfs(v, min(mf, e[i].c));
      mf -= f;
      e[i].c -= f;
      e[i ^ 1].c += f;
      sum += f;
      if (mf == 0)
        break;
    }
  }
  if (sum == 0)
    d[u] = 0;
  return sum;
}
int dinic() {
  int flow = 0;
  while (bfs()) {
    memcpy(cur, h, sizeof(h));
    flow += dfs(s, 1e9);
  }
  return flow;
}
int main() {
  int n, m;
  cin >> n >> m;
  s = n + 1, t = s + 1;
  for (int i = 1; i <= n; i++) {
    int tt;
    cin >> tt;
    if (tt == 0)
      add(s, i, 1);
    else
      add(i, t, 1);
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    add(u, v, 1);
  }
  cout << dinic() << "\n";
  return 0;
}