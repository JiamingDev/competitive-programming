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
const int mod = 998244353, N = 1e5 + 5;
int a[N];
struct node {
  int l, r, sum, len, lb, rb, mb, lc, rc, mc, tag = -1, rev;
} tr[N * 4];
void pushup(node &t, node l, node r) {
  t.len = l.len + r.len;
  t.sum = l.sum + r.sum;
  t.lb = l.lb == l.len ? l.lb + r.lb : l.lb;
  t.rb = r.rb == r.len ? r.rb + l.rb : r.rb;
  t.lc = l.lc == l.len ? l.lc + r.lc : l.lc;
  t.rc = r.rc == r.len ? r.rc + l.rc : r.rc;
  t.mb = max({l.mb, r.mb, l.rb + r.lb});
  t.mc = max({l.mc, r.mc, l.rc + r.lc});
}
void build(int p, int l, int r) {
  int t = a[l];
  tr[p] = {l, r, t, r - l + 1, t, t, t, t ^ 1, t ^ 1, t ^ 1};
  if (l == r) {
    tr[p].lb = tr[p].rb = tr[p].mb = a[l] == 1;
    tr[p].lc = tr[p].rc = tr[p].mc = a[l] == 0;
    return;
  }
  int mid = l + r >> 1;
  build(ls, l, mid);
  build(rs, mid + 1, r);
  pushup(tr[p], tr[ls], tr[rs]);
}
void update(int, int);
void pd(int p) {
  auto &t = tr[p];
  if (t.tag != -1) {
    update(ls, t.tag);
    update(rs, t.tag);
  }
  if (t.rev) {
    update(ls, 2);
    update(rs, 2);
  }
  t.tag = -1;
  t.rev = 0;
}
node query(int p, int x, int y) {
  auto &t = tr[p];
  if (x <= t.l && t.r <= y)
    return t;
  int mid = t.l + t.r >> 1;
  node temp;
  pd(p);
  if (x <= mid && y > mid) {
    pushup(temp, query(ls, x, y), query(rs, x, y));
    return temp;
  }
  if (x <= mid)
    return query(ls, x, y);
  return query(rs, x, y);
}
void update(int p, int k) {
  auto &t = tr[p];
  if (k <= 1) {
    t.sum = t.lb = t.rb = t.mb = k * t.len;
    t.lc = t.rc = t.mc = !k * t.len;
    t.tag = k;
    t.rev = 0;
  } else {
    t.sum = t.len - t.sum;
    swap(t.lb, t.lc);
    swap(t.rb, t.rc);
    swap(t.mb, t.mc);
    t.rev ^= 1;
  }
}
void change(int p, int x, int y, int k) {
  auto &t = tr[p];
  if (x <= t.l && y >= t.r) {
    update(p, k);
    return;
  }
  if (x > t.r || y < t.l)
    return;
  pd(p);
  change(ls, x, y, k);
  change(rs, x, y, k);
  pushup(t, tr[ls], tr[rs]);
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  build(1, 0, n - 1);
  for (int i = 0; i < m; i++) {
    int k, l, r;
    cin >> k >> l >> r;
    if (k <= 2) {
      change(1, l, r, k);
    } else {
      auto t = query(1, l, r);
      cout << (k == 3 ? t.sum : t.mb) << "\n";
    }
  }
  return 0;
}