#include <bits/stdc++.h>
using namespace std;
using ll = long long;
char a[105][105];
vector<int> g[105 * 105];
int cnt, vis[105 * 105], match[105 * 105];
pair<int, int> id[105][105];
void add(int u, int v) {
  g[u].push_back(v);
  g[v].push_back(u);
}
bool dfs(int u) {
  memset(vis, 0, sizeof(vis));
  for (int x : g[u])
    if (!vis[x]) {
      vis[x] = true;
      if (!match[x] || dfs(match[x])) {
        match[x] = u;
        return true;
      }
    }
  return false;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    cnt = 1;
    memset(a, 0, sizeof(a));
    int H, w;
    cin >> H >> w;
    for (int i = 1; i <= H * w; i++)
      g[i].clear();
    int p;
    cin >> p;
    for (int i = 0; i < p; i++) {
      int u, v;
      cin >> u >> v;
      a[u][v] = '*';
    }
    cin >> p;
    for (int i = 0; i < p; i++) {
      int u, v;
      cin >> u >> v;
      a[u][v] = '#';
    }
    for (int i = 1; i <= H; i++)
      for (int j = 1; j <= w; j++) {
        if (j == w || a[i][j] == '#') {
          cnt++;
        }
        if (a[i][j] == '*')
          id[i][j].first = cnt;
      }
    int mid = cnt;
    cnt++;
    for (int j = 1; j <= w; j++)
      for (int i = 1; i <= H; i++) {
        if (i == H || a[i][j] == '#') {
          cnt++;
        }
        if (a[i][j] == '*')
          id[i][j].second = cnt;
      }
    for (int i = 1; i <= H; i++)
      for (int j = 1; j <= w; j++)
        if (a[i][j] == '*') {
          add(id[i][j].first, id[i][j].second);
        }
    int ans = 0;
    memset(match, 0, sizeof(match));
    for (int i = 1; i <= mid; i++)
      if (dfs(i))
        ans++;
    cout << ans << "\n";
  }
  return 0;
}