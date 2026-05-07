#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, n) for (int i = 0; i < (n); i++)
signed main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    vector<pair<int, int>> op;
    int st = 3;
    if (!a[0] || !a[1]) {
      op.push_back({1, 2});
      n--;
      st = 2;
    }
    if (find(a.begin() + 2, a.end(), 0) != a.end()) {
      op.push_back({st, n});
      n = st;
    }
    op.push_back({1, n});
    cout << op.size() << "\n";
    for (auto [l, r] : op)
      cout << l << " " << r << "\n";
  }
  return 0;
}