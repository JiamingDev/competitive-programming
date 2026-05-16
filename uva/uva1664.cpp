#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 200005;
struct edge {
  int u, v, c;
  bool operator<(const edge &b) const {
    return c > b.c;
  }
} e[maxn];
ll cnt[maxn], fa[maxn], dp[maxn];
int find(int u) {
  return fa[u] == u ? u : fa[u] = find(fa[u]);
}
int main() {
  int n;
  while (cin >> n) {
    for (int i = 1; i <= n; i++)
      fa[i] = i;
    fill(cnt, cnt + n + 1, 1);
    fill(dp, dp + n + 1, 0);
    for (int i = 0; i < n - 1; i++)
      cin >> e[i].u >> e[i].v >> e[i].c;
    sort(e, e + n - 1);
    int u, v, c;
    for (int i = 0; i < n - 1; i++) {
      u = find(e[i].u), v = find(e[i].v), c = e[i].c;
      fa[v] = u;
      dp[u] = max(cnt[v] * c + dp[u], cnt[u] * c + dp[v]);
      cnt[u] += cnt[v];
    }
    cout << dp[u] << "\n";
  }
  return 0;
}