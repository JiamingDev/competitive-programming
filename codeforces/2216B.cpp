#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int T;
  cin >> T;
  while (T--) {
    ll t, h, u;
    cin >> t >> h >> u;
    ll sum = 3 * (t + h + u);
    if (t > 0 && u > 0) {
      ll cnt = min(t, u);
      sum -= cnt * 2;
      t -= cnt;
      u -= cnt;
    }
    if (t > 0 && h > 0) {
      ll cnt = min(2 * h, t);
      sum -= cnt;
      t -= cnt;
    }
    if (t > 0)
      sum -= t - 1;
    cout << sum << "\n";
  }
  return 0;
}