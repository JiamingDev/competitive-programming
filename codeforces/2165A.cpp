#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
signed main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    list<int> l;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      l.push_back(i);
    }
    auto nprev = [&](auto it) {
      return it == l.begin() ? prev(l.end()) : prev(it);
    };
    auto nnext = [&](auto it) {
      return it == prev(l.end()) ? l.begin() : next(it);
    };
    auto hole = [&](auto it) {
      return a[*it] <= a[*nprev(it)] && a[*it] <= a[*nnext(it)];
    };
    queue<list<int>::iterator> q;
    vector<bool> mark(n);
    for (auto it = l.begin(); it != l.end(); it++)
      if (hole(it)) {
        q.push(it);
        mark[*it] = 1;
      }
    int ans = 0;
    while (l.size() > 1) {
      auto it = q.front();
      q.pop();
      auto lef = nprev(it), righ = nnext(it);
      l.erase(it);
      ans += min(a[*lef], a[*righ]);
      if (!mark[*lef] && hole(lef)) {
        q.push(lef);
        mark[*lef] = 1;
      }
      if (!mark[*righ] && hole(righ)) {
        q.push(righ);
        mark[*righ] = 1;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}