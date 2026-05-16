#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define ls p << 1
#define rs p << 1 | 1
const int inf = 0x3f3f3f3f;
const ll inf_ll = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353, N = 2e5 + 5;
struct node {
  int l, r, len, sum, lx, rx, mx, tag;
} tr[4 * N];
void build(int p, int l, int r) {
  tr[p] = {l, r, r - l + 1, r - l + 1, 0, 0, 0, -1};
  if (l == r)
    return;
  int mid = l + r >> 1;
  build(ls, l, mid);
  build(rs, mid + 1, r);
}
void pd(int p, int v) {
  auto &t = tr[p];
  t.lx = t.rx = t.mx = (v == 0) * t.len;
  if (v == 0)
    t.sum = 0;
  else
    t.sum = t.len;
  t.tag = v;
}
void pushdown(int p) {
  auto &t = tr[p].tag;
  if (t != -1) {
    pd(ls, t);
    pd(rs, t);
  }
  t = -1;
}
void pushup(node &t, node l, node r) {
  t.len = l.len + r.len;
  t.sum = l.sum + r.sum;
  t.lx = l.sum ? l.lx : l.len + r.lx;
  t.rx = r.sum ? r.rx : r.len + l.rx;
  t.mx = max({l.mx, r.mx, l.rx + r.lx});
}
void change(int p, int x, int y, int v) {
  auto &t = tr[p];
  if (x <= t.l && t.r <= y) {
    pd(p, v);
    return;
  }
  pushdown(p);
  int mid = t.l + t.r >> 1;
  if (x <= mid)
    change(ls, x, y, v);
  if (y > mid)
    change(rs, x, y, v);
  pushup(t, tr[ls], tr[rs]);
}
node query(int p, int x, int y) {
  auto &t = tr[p];
  if (x <= t.l && t.r <= y)
    return t;
  pushdown(p);
  int mid = t.l + t.r >> 1;
  if (x > mid)
    return query(rs, x, y);
  if (y <= mid)
    return query(ls, x, y);
  node temp;
  pushup(temp, query(ls, x, y), query(rs, x, y));
  return temp;
}
void work(int l, int r, int cnt) {
  int ans = -1;
  int st = l;
  while (l <= r) {
    int mid = l + r >> 1;
    auto t = query(1, st, mid);
    if (t.len - t.sum <= cnt) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  if (ans != -1)
    change(1, st, ans, 1);
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  build(1, 1, n);
  for (int i = 0; i < m; i++) {
    int k, l, r;
    cin >> k >> l >> r;
    if (k == 0)
      change(1, l, r, 0);
    else if (k == 1) {
      int l1, r1;
      cin >> l1 >> r1;
      auto t = query(1, l, r);
      change(1, l, r, 0);
      work(l1, r1, t.sum);
    } else {
      auto t = query(1, l, r);
      cout << t.mx << "\n";
    }
  }
  return 0;
}