#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
const int maxn = 2e5 + 5, mod1 = 1000000007, mod2 = 1000000009, B = 1331;
struct Hash {
  int x, y;
  bool operator==(const Hash &b) const {
    return tie(x, y) == tie(b.x, b.y);
  }
} h2[maxn], pw[2 * maxn], rh[maxn];
Hash add(Hash a, int v) {
  return {(a.x * B + v) % mod1, (a.y * B + v) % mod2};
}
Hash sub(Hash a, Hash b, int len) {
  return {(a.x - b.x * pw[len].x % mod1 + mod1) % mod1, (a.y - b.y * pw[len].y % mod2 + mod2) % mod2};
}
bool check(int pos, int len) {
  return sub(h2[pos + len - 1], h2[pos - 1], 2 * len) == sub(rh[pos - 2 * len], rh[pos], 2 * len);
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  s = " " + s;
  pw[0] = {1, 1};
  for (int i = 1; i <= n; i++) {
    pw[i].x = pw[i - 1].x * B % mod1;
    pw[i].y = pw[i - 1].y * B % mod2;
  }
  for (int i = 1; i <= n; i++) {
    h2[i] = add(h2[i - 1], s[i]);
    h2[i] = add(h2[i], s[i]);
  }
  for (int i = n; i >= 1; i--)
    rh[i] = add(rh[i + 1], s[i]);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int l = 0, r = min(n - i + 1, (i - 1) / 2);
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
  cout << ans;
  return 0;
}