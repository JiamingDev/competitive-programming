#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 105, INF = 0x3f3f3f3f;
struct edge {
  int v, c, ne;
} e[100000], temp[100000];
int a[maxn], s, t, tot, h[maxn * 3], border[maxn], n, d[maxn * 3], cur[3 * maxn], ttot, th[maxn * 3];
void add(int u, int v, int c) {
  e[++tot] = {v, c, h[u]};
  h[u] = tot;
  e[++tot] = {u, 0, h[v]};
  h[v] = tot;
}
bool bfs() {
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
int dfs(int u, int mf) {
  if (u == t)
    return mf;
  int sum = 0;
  for (int &i = cur[u]; i; i = e[i].ne) {
    int v = e[i].v;
    if (d[v] == d[u] + 1 && e[i].c) {
      int f = dfs(v, min(mf, e[i].c));
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
int dinic() {
  int flow = 0;
  while (bfs()) {
    memcpy(cur, h, sizeof(h));
    flow += dfs(s, INF);
  }
  return flow;
}
bool check(int x) {
  int sum = 0;
  for (int i = 1; i <= n; i++)
    if (border[i]) {
      add(i + n, t, x);
      sum += x;
    } else if (a[i]) {
      add(i + n, t, 1);
      sum += 1;
    }
  return dinic() == sum;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    memset(border, 0, sizeof(border));
    memset(h, 0, sizeof(h));
    tot = 1;
    cin >> n;
    t = n + n + 1;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i]) {
        add(i, i + n, INF);
        add(s, i, a[i]);
      }
    }
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) {
        char chr;
        cin >> chr;
        if (a[i] && chr == 'Y') {
          if (a[j] == 0) {
            border[i] = 1;
            continue;
          }
          add(i, j + n, INF);
        }
      }
    memcpy(th, h, sizeof(h));
    ttot = tot;
    memcpy(temp, e, sizeof(e));
    int l = 1, r = 10005;
    while (l < r) {
      int mid = l + (r - l - 1 + 2) / 2;
      if (check(mid))
        l = mid;
      else
        r = mid - 1;
      memcpy(h, th, sizeof(th));
      tot = ttot;
      memcpy(e, temp, sizeof(temp));
    }
    cout << l << "\n";
  }
  return 0;
}