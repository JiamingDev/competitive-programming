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
    set<int> s;
    s.insert(a[0]);
    int ans = 1;
    int idx = 1;
    for (;;) {
      set<int> ns;
      while (idx < n && s.size()) {
        s.erase(a[idx]);
        ns.insert(a[idx]);
        idx++;
      }
      if (s.empty()) {
        ans++;
        s = ns;
      } else
        break;
    }
    cout << ans << "\n";
  }
  return 0;
}