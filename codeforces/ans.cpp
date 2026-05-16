#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 500000 + 5;
const ll MOD1 = 1000000007;
const ll MOD2 = 1000000009;
const ll BASE = 911382323;
struct Hash {
  ll x, y;
  bool operator==(const Hash &other) const {
    return x == other.x && y == other.y;
  }
};
Hash add(Hash a, int v) {
  return {(a.x * BASE + v) % MOD1, (a.y * BASE + v) % MOD2};
}
Hash subHash(Hash a, Hash b, int len, vector<Hash> &pw) {
  ll x = (a.x - b.x * pw[len].x % MOD1 + MOD1) % MOD1;
  ll y = (a.y - b.y * pw[len].y % MOD2 + MOD2) % MOD2;
  return {x, y};
}
int n;
string s;
vector<Hash> rh, h2, pw;
bool check(int pos, int len) {
  if (pos - 2 * len < 1)
    return false;
  if (pos + len - 1 > n)
    return false;
  Hash left = subHash(rh[pos - 2 * len], rh[pos], 2 * len, pw);
  Hash right = subHash(h2[pos + len - 1], h2[pos - 1], 2 * len, pw);
  return left == right;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> s;
  n = s.size();
  s = " " + s;
  rh.assign(n + 5, {0, 0});
  h2.assign(n + 5, {0, 0});
  pw.assign(2 * n + 5, {1, 1});
  for (int i = 1; i <= 2 * n; i++) {
    pw[i].x = pw[i - 1].x * BASE % MOD1;
    pw[i].y = pw[i - 1].y * BASE % MOD2;
  }
  // rh[i] 表示从右往左构造的哈希
  for (int i = n; i >= 1; i--) {
    int v = s[i] - 'a' + 1;
    rh[i] = add(rh[i + 1], v);
  }
  // h2[i] 表示 s[1..i] 每个字符重复两次后的哈希
  for (int i = 1; i <= n; i++) {
    int v = s[i] - 'a' + 1;
    h2[i] = add(h2[i - 1], v);
    h2[i] = add(h2[i], v);
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int l = 0;
    int r = min((i - 1) / 2, n - i + 1);
    int maxlen = 0;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (check(i, mid)) {
        maxlen = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    ans += maxlen;
  }
  cout << ans << '\n';
  return 0;
}