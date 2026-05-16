#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e4 + 5;
int m[maxn], sum[maxn], x[maxn], dx[maxn];
signed main() {
  int n, M, y;
  cin >> n >> M >> y;
  for (int i = 0; i < n; i++)
    cin >> m[i];
  sum[n] = M;
  for (int i = n - 1; i >= 0; i--)
    sum[i] = sum[i + 1] + m[i];
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < n; i++)
    dx[i] = abs(x[i] - x[i + 1]);
  dx[n] = abs(x[n] - 0);
  double l = 0, r = M;
  vector<double> yy(n + 1);
  for (int i = 0; i < 100; i++) {
    double lam = (l + r) / 2;
    double sumy = 0;
    for (int i = 0; i < n + 1; i++) {
      yy[i] = sqrt(lam * lam * dx[i] * dx[i] / (sum[i] * sum[i] - lam * lam));
      sumy += yy[i];
    }
    if (sumy < y)
      l = lam;
    else
      r = lam;
  }
  double ans = 0;
  for (int i = 0; i < n + 1; i++)
    ans += sum[i] * sqrt(dx[i] * dx[i] + yy[i] * yy[i]);
  printf("%.8f", ans);
  return 0;
}