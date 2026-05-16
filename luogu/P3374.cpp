#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lc p << 1
#define rc p << 1 | 1
const int maxn = 5e5 + 5;
struct node {
  int l, r, sum, add;
} tr[4 * maxn];
int w[maxn];
void pushup(int p) {
  tr[p].sum = tr[lc].sum + tr[rc].sum;
}
void build(int p, int x, int y) {
  tr[p] = {x, y, w[x]};
  if (x == y)
    return;
  int m = x + y >> 1;
  build(lc, x, m);
  build(rc, m + 1, y);
  pushup(p);
}
void pushdown(int p) {
  if (tr[p].add) {
    int &k = tr[p].add;
    tr[lc].sum += k * (tr[lc].r - tr[lc].l + 1);
    tr[rc].sum += k * (tr[rc].r - tr[rc].l + 1);
    tr[lc].add += k;
    tr[rc].add += k;
    k = 0;
  }
}
void update(int p, int x, int y, int k) {
  int l = tr[p].l, r = tr[p].r;
  if (x <= tr[p].l && tr[p].r <= y) {
    tr[p].sum += k * (r - l + 1);
    tr[p].add += k;
    return;
  }
  int m = tr[p].l + tr[p].r >> 1;
  pushdown(p);
  if (x <= m)
    update(lc, x, y, k);
  if (y > m)
    update(rc, x, y, k);
  pushup(p);
}
int query(int p, int x, int y) {
  if (x <= tr[p].l && y >= tr[p].r)
    return tr[p].sum;
  int sum = 0;
  int m = tr[p].l + tr[p].r >> 1;
  pushdown(p);
  if (x <= m)
    sum += query(lc, x, y);
  if (y > m)
    sum += query(rc, x, y);
  return sum;
}
signed main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> w[i];
  build(1, 1, n);
  for (int i = 0; i < m; i++) {
    int op, x, y, k;
    cin >> op;
    if (op == 1) {
      cin >> x >> y >> k;
      update(1, x, y, k);
    } else {
      cin >> x >> y;
      cout << query(1, x, y) << "\n";
    }
  }
  return 0;
}