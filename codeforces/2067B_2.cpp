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
    sort(a.begin(), a.end());
    int mx = 0;
    bool ok = 1;
    for (int i = 0; i < n; i += 2) {
      if (max(mx, a[i]) != max(mx, a[i + 1])) {
        ok = 0;
        break;
      }
      mx = max(mx, a[i]) + 1;
    }
    if (!ok)
      cout << "No\n";
    else
      cout << "Yes\n";
  }
  return 0;
}