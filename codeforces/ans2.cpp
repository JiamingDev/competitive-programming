#include <bits/stdc++.h>
using namespace std;
mt19937_64 rnd(time(0));
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using dl = __int128;
#define lowbit(x) ((x) & -(x))
constexpr ull B = 1428571, I = 9964865885124592595ull;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;
constexpr int N = 5e5 + 9, R = 998244353;
int n, m, qq, ql, qr, pa[N], sz[N], de[N], hf[N], mxd, disc[N], top[N], low[N], in[N];
ll ans, a[N], b[N], c[N];
basic_string<int> adj[N], bdj[N], ndj[N];
stack<int> stk;
queue<int> q;
string s;
ull pw[N], ipw[N], lhsh[N], rhsh[N]; // lhsh is 2 - expanded
bool check(int x, int len) {
  if (x + len - 1 > n)
    return 0;
  if (x - len * 2 < 1)
    return 0;
  return lhsh[x + len - 1] - lhsh[x - 1] * pw[len * 2] == rhsh[x - len * 2] - rhsh[x] * pw[len * 2];
}
signed main() {
  pw[0] = 1;
  for (int i = 1; i < N; i++)
    pw[i] = pw[i - 1] * B;
  ipw[0] = 1;
  for (int i = 1; i < N; i++)
    ipw[i] = ipw[i - 1] * I;
  cin.tie(0)->sync_with_stdio(0);
  cin >> s;
  n = s.size();
  s = ' ' + s;
  for (int i = n; i; i--) {
    rhsh[i] = rhsh[i + 1] * B + s[i]; // aabcgf: f, fg, fgc, fgcb, ...
  }
  for (int i = 1; i <= n; i++) {
    lhsh[i] = lhsh[i - 1] * B + s[i];
    lhsh[i] = lhsh[i] * B + s[i];
  }
  for (int i = 1; i <= n; i++) {
    int len = 0;
    for (int l = 0, mid, r = N; l <= r;) { // maximize
      mid = l + (r - l) / 2;
      if (check(i, mid))
        l = (len = mid) + 1;
      else
        r = mid - 1;
    }
    ans += len;
  }
  cout << ans;
  return 0;
}
