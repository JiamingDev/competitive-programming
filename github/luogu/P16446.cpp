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
#define int long long
const int inf = 0x3f3f3f3f;
const ll inf_ll = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353, N = 5e5 + 5;
struct node {
  int suma0, sumb0, suma1, sumb1, cnt0, cnt1, ans, mina, mina0, maxa, minb, maxb0, maxb, taga, tagb;
} tr[N * 4];
void pushup(int p) {
  auto &t = tr[p], &l = tr[ls], &r = tr[rs];
  t = {l.suma0 + r.suma0, l.sumb0 + r.sumb0, l.suma1 + r.suma1, l.sumb1 + r.sumb1, l.cnt0 + r.cnt0, l.cnt1 + r.cnt1, l.ans + r.ans, min(l.mina, r.mina), min(l.mina0, r.mina0), max(l.maxa, r.maxa), min(l.minb, r.minb), max(l.maxb0, r.maxb0), max(l.maxb, r.maxb), inf, inf};
}
void apply_a(int p, int v) {
  auto &t = tr[p];
  t.maxa = t.mina = v;
  t.ans = t.cnt0 * v - t.sumb0 + t.sumb1 - t.cnt1 * v;
  t.suma0 = t.cnt0 * v;
  t.suma1 = t.cnt1 * v;
  if (t.mina0 != inf)
    t.mina0 = v;
  t.taga = v;
}
void apply_b(int p, int v) {
  auto &t = tr[p];
  t.ans = t.suma0 - t.cnt0 * v + t.cnt1 * v - t.suma1;
  t.maxb = t.minb = v;
  t.sumb0 = t.cnt0 * v;
  t.sumb1 = t.cnt1 * v;
  if (t.maxb0 != -inf)
    t.maxb0 = v;
  t.tagb = v;
}
void build(int p, int l, int r, int A, int B) {
  if (A >= B) {
    tr[p] = {A, B, 0, 0, 1, 0, A - B, A, A, A, B, B, B, inf, inf};
  } else {
    tr[p] = {0, 0, A, B, 0, 1, B - A, A, inf, A, B, -inf, B, inf, inf};
  }
  if (l == r)
    return;
  int mid = l + r >> 1;
  build(ls, l, mid, A, B);
  build(rs, mid + 1, r, A, B);
  pushup(p);
}
void pushdown(int p) {
  auto &t = tr[p], &l = tr[ls], &r = tr[rs];
  if (t.taga != inf) {
    apply_a(ls, t.taga);
    apply_a(rs, t.taga);
  }
  if (t.tagb != inf) {
    apply_b(ls, t.tagb);
    apply_b(rs, t.tagb);
  }
  t.taga = t.tagb = inf;
}
void check_flip(int p, int l, int r) {
  auto &t = tr[p];
  if (t.mina0 - t.maxb0 > 0)
    return;
  if (l == r) {
    t.ans = t.minb - t.maxa;
    t.cnt0 = 0;
    t.cnt1 = 1;
    t.suma0 = t.sumb0 = 0;
    t.sumb1 = t.minb;
    t.suma1 = t.mina;
    t.mina0 = inf;
    t.maxb0 = -inf;
    return;
  }
  pushdown(p);
  int mid = l + r >> 1;
  check_flip(ls, l, mid);
  check_flip(rs, mid + 1, r);
  pushup(p);
}
void update_a(int p, int l, int r, int x, int y, int v) {
  auto &t = tr[p];
  if (x <= l && r <= y) {
    if (t.mina >= v) {
      apply_a(p, v);
      check_flip(p, l, r);
      return;
    }
    if (t.maxa <= v)
      return;
  }
  pushdown(p);
  int mid = l + r >> 1;
  if (x <= mid)
    update_a(ls, l, mid, x, y, v);
  if (y > mid)
    update_a(rs, mid + 1, r, x, y, v);
  pushup(p);
}
void update_b(int p, int l, int r, int x, int y, int v) {
  auto &t = tr[p];
  if (x <= l && r <= y) {
    if (t.maxb <= v) {
      apply_b(p, v);
      check_flip(p, l, r);
      return;
    }
    if (t.minb >= v)
      return;
  }
  pushdown(p);
  int mid = l + r >> 1;
  if (x <= mid)
    update_b(ls, l, mid, x, y, v);
  if (y > mid)
    update_b(rs, mid + 1, r, x, y, v);
  pushup(p);
}
int query(int p, int l, int r, int x, int y) {
  if (y < l || x > r)
    return 0;
  auto &t = tr[p];
  if (x <= l && r <= y)
    return t.ans;
  pushdown(p);
  int mid = l + r >> 1;
  return query(ls, l, mid, x, y) + query(rs, mid + 1, r, x, y);
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, A, B, Q;
  cin >> n >> A >> B >> Q;
  build(1, 1, n, A, B);
  for (int i = 0; i < Q; i++) {
    int op;
    cin >> op;
    if (op == 1) {
      int r, x;
      cin >> r >> x;
      update_a(1, 1, n, 1, r, x);
    } else if (op == 2) {
      int l, x;
      cin >> l >> x;
      update_b(1, 1, n, l, n, x);
    } else {
      int x, y;
      cin >> x >> y;
      cout << query(1, 1, n, x, y) << "\n";
    }
  }
  return 0;
}