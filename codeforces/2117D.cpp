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
    int diff = 0;
    bool ok = 1;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (i == 1) {
        diff = a[i] - a[i - 1];
      } else if (i && a[i] - a[i - 1] != diff)
        ok = 0;
    }
    if (diff < 0)
      diff = -diff;
    int fin = min(a[0], a[n - 1]) - diff;
    if (!ok || fin < 0 || fin % (n + 1))
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}