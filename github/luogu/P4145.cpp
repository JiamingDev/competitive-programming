#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define lc p << 1
#define rc p << 1 | 1
#define mid (l + r >> 1)
#define int long long
const int inf = 0x3f3f3f3f;
const ll inf_ll = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353, N = 1e5 + 5;
int a[N], sum[N * 4], mx[N * 4];
void pushup(int p) {
  sum[p] = sum[lc] + sum[rc];
  mx[p] = max(mx[lc], mx[rc]);
}
void build(int p, int l, int r) {
  sum[p] = mx[p] = a[l];
  if (l == r)
    return;
  build(lc, l, mid);
  build(rc, mid + 1, r);
  pushup(p);
}
int query(int p, int l, int r, int x, int y) {
  if (x <= l && r <= y)
    return sum[p];
  int res = 0;
  if (x <= mid)
    res += query(lc, l, mid, x, y);
  if (y > mid)
    res += query(rc, mid + 1, r, x, y);
  return res;
}
void update(int p, int l, int r, int x, int y) {
  if (mx[p] == 1)
    return;
  if (l == r) {
    sum[p] = mx[p] = sqrt(mx[p]);
    return;
  }
  if (x <= mid)
    update(lc, l, mid, x, y);
  if (y > mid)
    update(rc, mid + 1, r, x, y);
  pushup(p);
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  build(1, 1, n);
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int k, l, r;
    cin >> k >> l >> r;
    if (l > r)
      swap(l, r);
    if (k)
      cout << query(1, 1, n, l, r) << "\n";
    else
      update(1, 1, n, l, r);
  }
  return 0;
}