#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 105;
int s, t;
struct edge {
  int v, c, ne;
} e[100000];
int tot, h[maxn], d[maxn], pre[maxn], mf[maxn];
void add(int u, int v, int c) {
  e[++tot] = {v, c, h[u]};
  h[u] = tot;
  e[++tot] = {u, c, h[v]};
  h[v] = tot;
}
bool bfs() {
  memset(d, 0, sizeof(d));
  memset(mf, 0, sizeof(mf));
  queue<int> q;
  q.push(s);
  d[s] = 1;
  mf[s] = 1e9;
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int i = h[u]; i; i = e[i].ne) {
      int v = e[i].v;
      if (e[i].c && mf[v] == 0) {
        mf[v] = min(mf[u], e[i].c);
        pre[v] = i;
        q.push(v);
        if (v == t)
          return true;
      }
    }
  }
  return false;
}
int EK() {
  int flow = 0;
  while (bfs()) {
    int tt = t;
    while (tt != s) {
      int i = pre[tt];
      e[i].c -= mf[t];
      e[i ^ 1].c += mf[t];
      tt = e[i ^ 1].v;
    }
    flow += mf[t];
  }
  return flow;
}
int main() {
  int n, kase = 0;
  while (cin >> n && n) {
    tot = 1;
    memset(h, 0, sizeof(h));
    int m;
    cin >> s >> t >> m;
    for (int i = 0; i < m; i++) {
      int u, v, c;
      cin >> u >> v >> c;
      add(u, v, c);
    }
    printf("Network %d\nThe bandwidth is %d.\n\n", ++kase, EK());
  }
  return 0;
}