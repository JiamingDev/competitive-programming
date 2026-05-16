#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5 + 5;
int col[maxn];
vector<int> g[maxn];
set<int> s[maxn];
int n, k, res;
void dfs(int u, int f) {
  s[u].insert(col[u]);
  for (int v : g[u])
    if (v != f) {
      dfs(v, u);
      if (s[u].size() < s[v].size())
        swap(s[u], s[v]);
      for (auto x : s[v])
        s[u].insert(x);
    }
  if (s[u].size() >= k) {
    s[u].clear();
    res++;
  }
}
signed main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> col[i];
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  cout << res << "\n";
  return 0;
}