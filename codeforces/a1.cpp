#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
signed main() {
  double x, y, t, v;
  cin >> x >> y >> t >> v;
  double r2 = x * x + y * y;
  cout << fixed << setprecision(9) << sqrt(2 * r2 - 2 * r2 * cos(2 * acos(-1) * (t * v - (int)(t * v))));
  return 0;
}