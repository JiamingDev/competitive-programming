#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
struct edge {
  int v, t;
  bool operator<(const edge &b) const {
    return t > b.t;
  }
};
vector<edge> g[105];
int T[10], d[105], vis[105];
int main() {
  int n, k;
  while (cin >> n >> k) {
    for (int i = 0; i < 105; i++)
      g[i].clear();
    for (int i = 1; i <= n; i++)
      cin >> T[i] >> ws;
    string s;
    for (int i = 1; i <= n; i++) {
      getline(cin, s);
      stringstream ss(s);
      vector<int> v;
      int t;
      while (ss >> t) {
        for (int j = 0; j < v.size(); j++) {
          int tim = abs(t - v[j]) * T[i];
          g[v[j]].push_back({t, tim});
          g[t].push_back({v[j], tim});
        }
        v.push_back(t);
      }
    }
    if (g[0].empty()) {
      cout << "IMPOSSIBLE\n";
      continue;
    }
    priority_queue<edge> pq;
    memset(vis, 0, sizeof(vis));
    memset(d, 0x3f, sizeof(d));
    pq.push({0, 0});
    d[0] = 0;
    while (pq.size()) {
      int u = pq.top().v, t = pq.top().t;
      pq.pop();
      if (u == k) {
        cout << t << "\n";
        break;
      }
      if (vis[u])
        continue;
      vis[u] = 1;
      int del = 60;
      if (u == 0)
        del = 0;
      for (auto x : g[u])
        if (t + x.t + del < d[x.v]) {
          d[x.v] = t + x.t + del;
          pq.push({x.v, d[x.v]});
        }
    }
    if (d[k] == INF)
      cout << "IMPOSSIBLE\n";
  }
  return 0;
}