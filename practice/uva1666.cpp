#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 55;
struct Rec {
  int x1, y1, x2, y2;
} rec[maxn];
struct sta {
  int x, y, q, dir;
};
int main() {
  int sx, sy, ex, ey;
  while (cin >> sx >> sy >> ex >> ey && !(sx == 0 && sy == 0 && ex == 0 && ey == 0)) {
    int n;
    cin >> n;
    vector<int> X = {sx, ex, (int)-2e8, (int)2e8}, Y = {sy, ey, (int)-2e8, (int)2e8};
    for (int i = 0; i < n; i++) {
      int x1, x2, y1, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      if (x1 > x2)
        swap(x1, x2);
      if (y1 > y2)
        swap(y1, y2);
      rec[i] = {x1, y1, x2, y2};
      X.push_back(x1), X.push_back(x2), Y.push_back(y1), Y.push_back(y2);
    }
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    sort(Y.begin(), Y.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());
    vector<vector<bool>> solid(X.size(), vector<bool>(Y.size()));
    for (int i = 0; i < n; i++) {
      int x1 = lower_bound(X.begin(), X.end(), rec[i].x1) - X.begin();
      int x2 = lower_bound(X.begin(), X.end(), rec[i].x2) - X.begin();
      int y1 = lower_bound(Y.begin(), Y.end(), rec[i].y1) - Y.begin();
      int y2 = lower_bound(Y.begin(), Y.end(), rec[i].y2) - Y.begin();
      for (int k = x1; k < x2; k++)
        for (int j = y1; j < y2; j++)
          solid[k][j] = 1;
    }
    sx = lower_bound(X.begin(), X.end(), sx) - X.begin();
    ex = lower_bound(X.begin(), X.end(), ex) - X.begin();
    sy = lower_bound(Y.begin(), Y.end(), sy) - Y.begin();
    ey = lower_bound(Y.begin(), Y.end(), ey) - Y.begin();
    vector<vector<vector<vector<int>>>> d(X.size(), vector<vector<vector<int>>>(Y.size(), vector<vector<int>>(4, vector<int>(4, 1e9))));
    deque<sta> dq;
    auto is_solid = [&](int x, int y, int q) -> bool {
      if (q == 1 || q == 2)
        x--;
      if (q == 2 || q == 3)
        y--;
      if (x < 0 || y < 0 || x >= (int)solid.size() || y >= (int)solid[0].size()) {
        return false; // 越界的地方都是空地
      }
      return solid[x][y];
    };
    for (int i = 0; i < 4; i++)
      if (!is_solid(sx, sy, i))
        for (int dir = 0; dir < 4; dir++) {
          dq.push_back({sx, sy, i, dir});
          d[sx][sy][i][dir] = 0;
        }
    int ans = 1e9;
    while (dq.size()) {
      auto t = dq.front();
      dq.pop_front();
      int x = t.x, y = t.y, q = t.q, odir = t.dir;
      if (x == ex && y == ey) {
        ans = min(ans, d[x][y][q][odir]);
        continue;
      }
      int dir = (odir + 1) % 4;
      if (d[x][y][q][dir] > d[x][y][q][odir] + 1) {
        d[x][y][q][dir] = d[x][y][q][odir] + 1;
        dq.push_back({x, y, q, dir});
      }
      dir = (odir + 3) % 4;
      if (d[x][y][q][dir] > d[x][y][q][odir] + 1) {
        d[x][y][q][dir] = d[x][y][q][odir] + 1;
        dq.push_back({x, y, q, dir});
      }
      // 右上左下
      if (odir == 0 && (q == 0 || q == 3)) {
        int nx = x + 1, nq = q == 0 ? 1 : 2;
        if (nx < X.size() && d[nx][y][nq][odir] > d[x][y][q][odir]) {
          d[nx][y][nq][odir] = d[x][y][q][odir];
          dq.push_front({nx, y, nq, odir});
        }
      }
      if (odir == 1 && (q == 0 || q == 1)) {
        int nx = x, ny = y + 1, nq = q == 0 ? 3 : 2;
        if (ny < Y.size() && d[nx][ny][nq][odir] > d[x][y][q][odir]) {
          d[nx][ny][nq][odir] = d[x][y][q][odir];
          dq.push_front({nx, ny, nq, odir});
        }
      }
      if (odir == 2 && (q == 2 || q == 1)) {
        int nx = x - 1, ny = y, nq = q == 2 ? 3 : 0;
        if (nx >= 0 && d[nx][ny][nq][odir] > d[x][y][q][odir]) {
          d[nx][ny][nq][odir] = d[x][y][q][odir];
          dq.push_front({nx, ny, nq, odir});
        }
      }
      if (odir == 3 && (q == 2 || q == 3)) {
        int nx = x, ny = y - 1, nq = q == 2 ? 1 : 0;
        if (ny >= 0 && d[nx][ny][nq][odir] > d[x][y][q][odir]) {
          d[nx][ny][nq][odir] = d[x][y][q][odir];
          dq.push_front({nx, ny, nq, odir});
        }
      }
      if (odir == 0 && (q == 1 || q == 2)) {
        int nq = q == 1 ? 0 : 3;
        if (!is_solid(x, y, nq) && d[x][y][nq][odir] > d[x][y][q][odir]) {
          d[x][y][nq][odir] = d[x][y][q][odir];
          dq.push_front({x, y, nq, odir});
        }
      }
      if (odir == 1 && (q == 2 || q == 3)) {
        int nq = q == 2 ? 1 : 0;
        if (!is_solid(x, y, nq) && d[x][y][nq][odir] > d[x][y][q][odir]) {
          d[x][y][nq][odir] = d[x][y][q][odir];
          dq.push_front({x, y, nq, odir});
        }
      }
      if (odir == 2 && (q == 0 || q == 3)) {
        int nq = q == 0 ? 1 : 2;
        if (!is_solid(x, y, nq) && d[x][y][nq][odir] > d[x][y][q][odir]) {
          d[x][y][nq][odir] = d[x][y][q][odir];
          dq.push_front({x, y, nq, odir});
        }
      }
      if (odir == 3 && (q == 1 || q == 0)) {
        int nq = q == 1 ? 2 : 3;
        if (!is_solid(x, y, nq) && d[x][y][nq][odir] > d[x][y][q][odir]) {
          d[x][y][nq][odir] = d[x][y][q][odir];
          dq.push_front({x, y, nq, odir});
        }
      }
    }
    if (ans == 1e9)
      ans = -1;
    cout << ans << "\n";
  }
  return 0;
}