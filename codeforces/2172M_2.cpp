#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 5;
vector<int> g[maxn];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> d(n + 1, -1);
  queue<int> q;
  d[1] = 0;
  q.push(1);
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int v : g[u])
      if (d[v] == -1) {
        d[v] = d[u] + 1;
        q.push(v);
      }
  }
  vector<int> mx(k + 1, -1);
  for (int i = 1; i <= n; i++)
    mx[a[i]] = max(d[i], mx[a[i]]);
  for (int i = 1; i <= k; i++)
    cout << mx[i] << " ";
  return 0;
}