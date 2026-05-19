#include <bits/stdc++.h>
using namespace std;
#define int long long
const double eps = 1e-8;
signed main() {
  int T;
  cin >> T;
  while (T--) {
    int n, x0, y0, x1, y1;
    cin >> n;
    cin >> x0 >> y0 >> x1 >> y1;
    int sumd = 0, maxt = 0;
    for (int i = 0; i < n; i++) {
      int t;
      cin >> t;
      maxt = max(t, maxt);
      sumd += t;
    }
    double d = sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));
    if (sumd > d - eps && maxt - (sumd - maxt) <= d)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}