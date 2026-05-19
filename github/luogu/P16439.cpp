#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 505;
char a[maxn][maxn];
int vis[maxn][maxn], dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
bool solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (!vis[i][j]) {
        vis[i][j] = 1;
        queue<pair<int, int>> q;
        char flag = a[i][j];
        q.push({i, j});
        int maxr = -1, maxc = -1, minr = 1e9, minc = 1e9, cnt = 0;
        while (q.size()) {
          auto [r, c] = q.front();
          q.pop();
          cnt++;
          maxc = max(maxc, c);
          maxr = max(maxr, r);
          minr = min(minr, r);
          minc = min(minc, c);
          for (int dir = 0; dir < 4; dir++) {
            int nr = r + dr[dir], nc = c + dc[dir];
            if (nr >= n || nr < 0 || nc >= m || nc < 0)
              continue;
            if (!vis[nr][nc] && a[nr][nc] == flag) {
              q.push({nr, nc});
              vis[nr][nc] = 1;
            }
          }
        }
        if (cnt != (maxr - minr + 1) * (maxc - minc + 1))
          return false;
      }
  return true;
}
signed main() {
  int T;
  cin >> T;
  while (T--) {
    memset(vis, 0, sizeof(vis));
    if (solve())
      cout << "yes\n";
    else
      cout << "no\n";
  }
  return 0;
}