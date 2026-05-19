#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (n); i++)
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<int> deg(n);
    forn(i, n - 1) {
      int u, v, x, y;
      cin >> u >> v >> x >> y;
      u--, v--;
      if (x > y) {
        g[v].push_back(u);
        deg[u]++;
      } else {
        g[u].push_back(v);
        deg[v]++;
      }
    }
    queue<int> q;
    forn(i, n) if (deg[i] == 0) q.push(i);
    vector<int> p(n);
    for (int i = 1; i <= n; i++) {
      int u = q.front();
      q.pop();
      p[u] = i;
      for (int v : g[u]) {
        deg[v]--;
        if (deg[v] == 0)
          q.push(v);
      }
    }
    forn(i, n) cout << p[i] << " ";
    cout << "\n";
  }
  return 0;
}