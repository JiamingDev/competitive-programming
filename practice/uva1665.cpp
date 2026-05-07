#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct node {
  int r, c, h;
  bool operator<(const node &b) {
    return h > b.h;
  }
} nod[1000005];
int que[100005], dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1}, fa[1000005], vis[1005][1005];
int find(int u) {
  return fa[u] == u ? u : fa[u] = find(fa[u]);
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    memset(vis, 0, sizeof(vis));
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        int pos = i * m + j;
        fa[pos] = pos;
        nod[pos] = {i, j};
        cin >> nod[pos].h;
      }
    sort(nod, nod + n * m);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
      cin >> que[i];
    reverse(que, que + q);
    int idx = 0;
    int ans = 0;
    vector<int> res;
    for (int i = 0; i < q; i++) {
      while (idx < n * m && nod[idx].h > que[i]) {
        ans++;
        int r = nod[idx].r, c = nod[idx].c;
        vis[r][c] = 1;
        for (int i = 0; i < 4; i++) {
          int nr = r + dr[i], nc = c + dc[i];
          if (nr < 0 || nr >= n || nc < 0 || nc >= m || !vis[nr][nc])
            continue;
          int u = find(r * m + c), v = find(nr * m + nc);
          if (u != v) {
            ans--;
            fa[u] = v;
          }
        }
        idx++;
      }
      res.push_back(ans);
    }
    reverse(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
      cout << res[i] << " ";
    cout << "\n";
  }
  return 0;
}