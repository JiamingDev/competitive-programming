#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 107;
const double eps = 1e-8;
struct hole {
  int x, y, z, r;
} h[maxn];
double d[maxn][maxn], ansd[maxn];
int vis[maxn];
int main() {
  int n, s = 0, t, kase = 0;
  while (cin >> n && n != -1) {
    t = n + 1;
    for (int i = 1; i <= n; i++)
      cin >> h[i].x >> h[i].y >> h[i].z >> h[i].r;
    cin >> h[s].x >> h[s].y >> h[s].z;
    h[s].r = 0;
    cin >> h[t].x >> h[t].y >> h[t].z;
    h[t].r = 0;
    for (int i = 0; i <= t; i++)
      for (int j = i + 1; j <= t; j++) {
        int sumr = h[i].r + h[j].r;
        double dist = sqrt((h[i].x - h[j].x) * (h[i].x - h[j].x) + (h[i].y - h[j].y) * (h[i].y - h[j].y) + (h[i].z - h[j].z) * (h[i].z - h[j].z));
        if (sumr > dist - eps)
          d[j][i] = d[i][j] = 0;
        else
          d[j][i] = d[i][j] = dist - sumr;
      }
    for (int i = 0; i <= t; i++)
      ansd[i] = 1e9;
    memset(vis, 0, sizeof(vis));
    ansd[s] = 0;
    vis[s] = 1;
    queue<int> q;
    q.push(s);
    while (q.size()) {
      int u = q.front();
      q.pop();
      vis[u] = 0;
      for (int i = 0; i <= t; i++)
        if (i != u && ansd[u] + d[u][i] < ansd[i]) {
          ansd[i] = ansd[u] + d[u][i];
          if (!vis[i]) {
            q.push(i);
            vis[i] = 1;
          }
        }
    }
    ansd[t] *= 10;
    printf("Cheese %d: Travel time = %d sec\n", ++kase, (int)round(ansd[t]));
  }
  return 0;
}