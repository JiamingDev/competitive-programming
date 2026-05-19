#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e6 + 5;
signed main() {
  int n, m;
  cin >> n >> m;
  vector<int> sum(maxn);
  for (int i = 1; i <= n; i++) {
    int t;
    cin >> t;
    sum[t] += i;
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    cout << sum[u] * sum[v] << "\n";
  }
  return 0;
}