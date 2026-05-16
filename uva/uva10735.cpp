#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct edge {
  int v, c, ne;
} e[2000];
struct edge0 {
  int v, ne;
} e0[1000];
int s, t, h0[105], tot0, tot, h[105], diff[105], V, E, d[105], cur[105], vis[400];
vector<int> wait, ans;
void add(int u, int v, int c, int c2) {
  e[++tot] = {v, c, h[u]};
  h[u] = tot;
  e[++tot] = {u, c2, h[v]};
  h[v] = tot;
}
void add0(int u, int v) {
  e0[++tot0] = {v, h0[u]};
  h0[u] = tot0;
}
bool bfs() {
  memset(d, 0, sizeof(d));
  d[s] = 1;
  queue<int> q;
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
      int f = dfs(v, min(e[i].c, mf));
      mf -= f;
      sum += f;
      e[i].c -= f;
      e[i ^ 1].c += f;
      if (mf == 0)
        break;
    }
  }
  return sum;
}
bool dinic() {
  while (bfs()) {
    memcpy(cur, h, sizeof(h));
    dfs(s, 1e9);
  }
  for (int i = h[s]; i; i = e[i].ne)
    if (e[i].c)
      return false;
  return true;
}
void dfs0(int u) {
  for (int &i = h0[u]; i;) {
    int v = e0[i].v;
    i = e0[i].ne;
    dfs0(v);
  }
  ans.push_back(u);
}
bool solve() {
  for (int i = 1; i <= V; i++)
    if (diff[i] % 2 == 0) {
      int need = diff[i] / 2;
      if (need > 0)
        add(s, i, need, 0);
      else if (need < 0)
        add(i, t, -need, 0);
    } else
      return false;
  if (dinic()) {
  } else
    return false;
  for (int j = 0; j < wait.size(); j++) {
    int i = wait[j];
    int u = e[i ^ 1].v, v = e[i].v;
    if (e[i].c)
      add0(v, u);
    else
      add0(u, v);
  }
  memset(vis, 0, sizeof(vis));
  dfs0(1);
  return true;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    ans.clear();
    wait.clear();
    memset(diff, 0, sizeof(diff));
    tot0 = tot = 1;
    memset(h, 0, sizeof(h));
    memset(h0, 0, sizeof(h0));
    cin >> V >> E;
    t = V + 1;
    for (int i = 0; i < E; i++) {
      int u, v;
      char temp;
      cin >> u >> v >> temp;
      if (temp == 'D') {
        diff[u]--;
        diff[v]++;
        add0(u, v);
      } else {
        add(v, u, 1, 0);
        wait.push_back(tot - 1);
        diff[v]++;
        diff[u]--;
      }
    }
    if (solve()) {
      reverse(ans.begin(), ans.end());
      for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");
    } else
      cout << "No euler circuit exist\n";
    if (T)
      cout << "\n";
  }
  return 0;
}