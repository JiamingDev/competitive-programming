#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 105, INF = 0x3f3f3f3f;
struct edge {
  int v, c;
  double w;
  int ne;
} e[2000];
int x[maxn], y[maxn], h[maxn], tot, diff[maxn], s, t, vis[maxn], mf[maxn], pre[maxn];
double d[maxn];
vector<int> g[maxn];
void add(int u, int v, int c, double w) {
  e[++tot] = {v, c, w, h[u]};
  h[u] = tot;
  e[++tot] = {u, 0, -w, h[v]};
  h[v] = tot;
}
int n;
double mcmf() {
  double res = 0;
  while (1) {
    for (int i = 0; i <= n + 1; i++)
      d[i] = 1e9;
    memset(vis, 0, sizeof(vis));
    memset(mf, 0, sizeof(mf));
    d[s] = 0;
    vis[s] = 1;
    queue<int> q;
    q.push(s);
    mf[s] = INF;
    while (q.size()) {
      int u = q.front();
      q.pop();
      vis[u] = 0;
      for (int i = h[u]; i; i = e[i].ne) {
        int v = e[i].v, c = e[i].c;
        double w = e[i].w;
        if (d[u] + w < d[v] - 1e-8 && c) {
          d[v] = d[u] + w;
          mf[v] = min(c, mf[u]);
          pre[v] = i;
          if (!vis[v]) {
            q.push(v);
            vis[v] = 1;
          }
        }
      }
    }
    if (mf[t] == 0)
      break;
    int tt = t;
    while (tt != s) {
      int i = pre[tt];
      e[i].c -= mf[t];
      e[i ^ 1].c += mf[t];
      tt = e[i ^ 1].v;
    }
    res += mf[t] * d[t];
  }
  return res;
}
int main() {
  int a, b, kase = 0;
  while (cin >> n >> a >> b) {
    t = n + 1;
    tot = 1;
    memset(h, 0, sizeof(h));
    memset(diff, 0, sizeof(diff));
    for (int i = 1; i <= n; i++)
      g[i].clear();
    for (int i = 1; i <= n; i++) {
      cin >> x[i] >> y[i];
      for (;;) {
        int v;
        cin >> v;
        if (v == 0)
          break;
        g[i].push_back(v);
      }
    }
    double ans = 0;
    for (int i = 1; i <= n; i++)
      for (int v : g[i]) {
        double cost = sqrt((x[v] - x[i]) * (x[v] - x[i]) + (y[v] - y[i]) * (y[v] - y[i])) * a - b;
        if (cost <= 0)
          add(i, v, 1, -cost);
        else {
          add(v, i, 1, cost);
          ans += cost;
          diff[v]++; // diff=in-out
          diff[i]--;
        }
      }
    for (int i = 1; i <= n; i++)
      if (diff[i] > 0)
        add(s, i, diff[i], 0);
      else
        add(i, t, -diff[i], 0);
    ans -= mcmf();
    if (ans < 0)
      ans = 0;
    printf("Case %d: %.2f\n", ++kase, ans);
  }
  return 0;
}