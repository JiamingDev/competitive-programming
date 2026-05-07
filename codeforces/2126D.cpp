#include <bits/stdc++.h>
using namespace std;
#define int long long
struct edge {
  int l, r;
  bool operator<(const edge &b) const {
    return l < b.l;
  }
};
#define forn(i, n) for (int i = 0; i < (n); i++)
signed main() {
  int T;
  cin >> T;
  while (T--) {
    vector<edge> e;
    int n, k;
    cin >> n >> k;
    forn(i, n) {
      int l, r, real;
      cin >> l >> r >> real;
      e.push_back({l, real});
    }
    sort(e.begin(), e.end());
    int last, st = -1;
    for (int i = 0; i < e.size(); i++)
      if (e[i].l <= k && k <= e[i].r) {
        st = i + 1;
        last = e[i].r;
        break;
      }
    if (st == -1)
      cout << k << "\n";
    else {
      for (int i = st; i < e.size(); i++)
        if (e[i].l <= last && e[i].r > last) {
          last = e[i].r;
        } else if (e[i].l > last)
          break;
      cout << last << "\n";
    }
  }
  return 0;
}