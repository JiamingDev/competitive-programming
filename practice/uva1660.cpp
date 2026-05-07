#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 150, INF = 0x3f3f3f3f;
struct edge {
  int v, c, ne;
} e[10000], temp[10000];
int tot, h[maxn], d[maxn], cur[maxn];
void add(int u, int v, int c, int c2) {
  e[++tot] = {v, c, h[u]};
  h[u] = tot;
  e[++tot] = {u, c2, h[v]};
  h[v] = tot;
}
bool bfs(int s, int t) {
  memset(d, 0, sizeof(d));
  queue<int> q;
  q.push(s);
  d[s] = 1;
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
int dfs(int u, int mf, int t) {
  if (u == t)
    return mf;
  int sum = 0;
  for (int &i = cur[u]; i; i = e[i].ne) {
    int v = e[i].v;
    if (e[i].c && d[v] == d[u] + 1) {
      int f = dfs(v, min(mf, e[i].c), t);
      mf -= f;
      sum += f;
      e[i].c -= f;
      e[i ^ 1].c += f;
      if (mf == 0)
        break;
    }
  }
  if (sum == 0)
    d[u] = 0;
  return sum;
}
int dinic(int s, int t) {
  int flow = 0;
  while (bfs(s, t)) {
    memcpy(cur, h, sizeof(h));
    flow += dfs(s, INF, t);
    if (flow >= INF)
      break;
  }
  return flow;
}
int main() {
  int n, m;
  while (cin >> n >> m) {
    tot = 1;
    memset(h, 0, sizeof(h));
    if (n == 0) {
      cout << 0 << "\n";
      continue;
    }
    if (n == 1) {
      cout << 1 << "\n";
      continue;
    }
    for (int i = 0; i < n; i++)
      add(i, i + n, 1, 0);
    for (int i = 0; i < m; i++) {
      int u, v;
      scanf(" (%d,%d)", &u, &v);
      add(u + n, v, INF, 0);
      add(v + n, u, INF, 0);
    }
    memcpy(temp, e, sizeof(e));
    int ans = INF;
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++) {
        memcpy(e, temp, sizeof(temp));
        ans = min(ans, dinic(i + n, j));
      }
    if (ans == INF)
      cout << n << "\n";
    else
      cout << ans << "\n";
  }
  return 0;
}