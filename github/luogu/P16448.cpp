#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
const ull B = 1428571, N = 5e5 + 5;
ull rh[N], h2[N], pw[2 * N];
int n;
bool check(int pos, int len) {
  if (pos - 2 * len < 1 || pos + len - 1 > n)
    return 0;
  return rh[pos - 2 * len] - rh[pos] * pw[2 * len] == h2[pos + len - 1] - h2[pos - 1] * pw[2 * len];
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  n = s.size();
  s = " " + s;
  pw[0] = 1;
  for (int i = 1; i <= 2 * n; i++)
    pw[i] = pw[i - 1] * B;
  for (int i = n; i >= 1; i--)
    rh[i] = rh[i + 1] * B + s[i];
  for (int i = 1; i <= n; i++) {
    h2[i] = h2[i - 1] * B + s[i];
    h2[i] = h2[i] * B + s[i];
  }
  ull ans = 0;
  for (int i = 1; i <= n; i++) {
    int l = 0, r = N;
    int maxlen = 0;
    while (l <= r) {
      int mid = l + r >> 1;
      if (check(i, mid)) {
        maxlen = mid;
        l = mid + 1;
      } else
        r = mid - 1;
    }
    ans += maxlen;
  }
  cout << ans << "\n";
  return 0;
}