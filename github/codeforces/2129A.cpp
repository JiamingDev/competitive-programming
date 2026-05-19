#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, n) for (int i = 0; i < (n); i++)
struct edge {
  int u, v, idx;
  bool operator<(const edge &b) const {
    return u < b.u;
  }
};
signed main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<edge> e(n);
    forn(i, n) {
      int u, v;
      cin >> u >> v;
      e[i] = {u, v, i};
    }
    sort(e.begin(), e.end());
    int last = -1;
    vector<int> pos;
    for (auto [u, v, idx] : e) {
      if (v > last) {
        last = v;
        pos.push_back(idx + 1);
      }
    }
    sort(pos.begin(), pos.end());
    cout << pos.size() << "\n";
    for (int x : pos)
      cout << x << " ";
    cout << "\n";
  }
  return 0;
}