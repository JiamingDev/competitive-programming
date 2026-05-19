#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
signed main() {
  double x, y, s3 = sqrt(3);
  cin >> x >> y;
  printf("%.8Lf %.8Lf", x / 2 + y / 2, s3 * x / 2 - s3 * y / 2); // format?
  return 0;
}