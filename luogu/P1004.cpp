#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct sta {
  int x1, x2, cnt;
};
int a[15][15], d[15][15][30];
int main() {
  int n;
  cin >> n;
  int x, y, c;
  while (cin >> x >> y >> c && x)
    a[x][y] = c;
  memset(d, 0xcf, sizeof(d));
  d[1][1][0] = a[1][1];
  int dx[] = {1, 0}, dy[] = {0, 1};
  for (int cnt = 0; cnt < 2 * n - 2; cnt++)
    for (int x1 = max(1 + cnt - (n - 1), 1); x1 <= min(cnt + 1, n); x1++)
      for (int x2 = max(1 + cnt - (n - 1), 1); x2 <= min(cnt + 1, n); x2++) {
        int y1 = cnt - (x1 - 1) + 1, y2 = cnt - (x2 - 1) + 1;
        for (int i = 0; i < 2; i++)
          for (int j = 0; j < 2; j++) {
            int nx1 = x1 + dx[i], ny1 = y1 + dy[i], nx2 = x2 + dx[j], ny2 = y2 + dy[j];
            if (nx1 <= n && ny1 <= n && nx2 <= n && ny2 <= n) {
              int t = a[nx1][ny1];
              if (nx1 != nx2)
                t += a[nx2][ny2];
              d[nx1][nx2][cnt + 1] = max(d[nx1][nx2][cnt + 1], d[x1][x2][cnt] + t);
            }
          }
      }
  cout << d[n][n][2 * n - 2] << "\n";
  return 0;
}