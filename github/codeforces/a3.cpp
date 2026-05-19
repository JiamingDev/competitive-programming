#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 5;
vector<int> g[maxn];
signed main() {
  int n, m;
  cin >> n >> m;
  vector<int> w(n + 1);
  for (int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;
    w[u]++;
    w[v]--;
  }
  int root = max_element(w.begin(), w.end()) - w.begin();
  for (int i = 1; i <= n; i++) {
    if (i == root)
      cout << "0 ";
    else
      cout << root << " ";
  }
  return 0;
}