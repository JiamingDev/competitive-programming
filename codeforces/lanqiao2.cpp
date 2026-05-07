#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, c, w;
int solve() {
  if (w == 0)
    return 0;
  if (w % c)
    return -1;
  w /= c;
  if (w > (1 + n) * n / 2)
    return -1;
  int l = 1, sum = 0;
  for (int r = 1; r <= n; r++) {
    sum += r;
    while (l <= r && sum > w) {
      sum -= l;
      l++;
    }
    if (sum == w)
      return 1;
  }
  return 2;
}
signed main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> c >> w;
    cout << solve() << "\n";
  }
  return 0;
}