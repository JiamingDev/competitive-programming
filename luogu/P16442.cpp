#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 5e5 + 5;
struct edge {
  int v, w, ne;
} e[maxn * 2];
int tot = 1, h[maxn];
void add(int u, int v, int w) {
  e[++tot] = {v, w, h[u]};
  h[u] = tot;
  e[++tot] = {u, w, h[v]};
  h[v] = tot;
}
signed main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    add(u, v, w);
  }
  vector<int> a(n + 1);
  vector<int> c(k + 1);
  for (int u = 1; u <= n; u++) {
    vector<int> modified;
    for (int i = h[u]; i; i = e[i].ne) {
      int v = e[i].v;
      if (!a[v])
        continue;
      if (c[a[v]] == 0)
        modified.push_back(a[v]);
      c[a[v]] += e[i].w;
    }
    if (modified.size() < k) {
      for (int j = 1; j <= modified.size() + 1; j++)
        if (c[j] == 0) {
          a[u] = j;
          break;
        }
    } else
      a[u] = min_element(c.begin() + 1, c.end()) - c.begin();
    for (int x : modified)
      c[x] = 0;
  }
  cout << "Yes\n";
  for (int i = 1; i <= n; i++)
    cout << a[i] << " ";
  return 0;
}