#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 105;
map<int, int> mp;
int tot, d[maxn][maxn];
int getid(int a) {
  if (mp.count(a))
    return mp[a];
  return mp[a] = ++tot;
}
int main() {
  int kase = 0;
  while (1) {
    memset(d, 0x3f, sizeof(d));
    tot = 0;
    mp.clear();
    int a, b;
    for (;;) {
      cin >> a >> b;
      if (!a)
        break;
      int u = getid(a), v = getid(b);
      d[u][v] = 1;
    }
    if (tot == 0)
      break;
    for (int i = 1; i <= tot; i++)
      d[i][i] = 0;
    for (int k = 1; k <= tot; k++)
      for (int i = 1; i <= tot; i++)
        for (int j = 1; j <= tot; j++)
          d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
    int ans = 0, sum = (tot - 1) * tot;
    for (int i = 1; i <= tot; i++)
      for (int j = 1; j <= tot; j++)
        if (i != j) {
          ans += d[i][j];
        }
    printf("Case %d: average length between pages = %.3f clicks\n", ++kase, (double)ans / sum);
  }
  return 0;
}