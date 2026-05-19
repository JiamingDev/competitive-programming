#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 5;
struct node {
  int d, u;
  bool operator<(const node &b) const {
    return d > b.d;
  }
};
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
  vector<int> d(n + 1, 1e9);
  priority_queue<node> pq;
  pq.push({0, 1});
  d[1] = 0;
  while (pq.size()) {
    auto [dist, u] = pq.top();
    pq.pop();
    if (dist > d[u])
      continue;
    for (int x : g[u])
      if (d[x] > d[u] + 1) {
        d[x] = d[u] + 1;
        pq.push({d[x], x});
      }
  }
  vector<int> mx(k + 1, -1);
  for (int i = 1; i <= n; i++)
    mx[a[i]] = max(d[i], mx[a[i]]);
  for (int i = 1; i <= k; i++)
    cout << mx[i] << " ";
  return 0;
}