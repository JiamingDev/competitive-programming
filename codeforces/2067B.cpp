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
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
      int t;
      cin >> t;
      cnt[t]++;
    }
    bool ok = 1;
    for (int i = 1; i < n; i++)
      if (cnt[i] >= 2)
        cnt[i + 1] += cnt[i] - 2;
      else if (cnt[i]) {
        ok = 0;
        break;
      }
    if (!ok || cnt[n] & 1)
      cout << "No\n";
    else
      cout << "Yes\n";
  }
  return 0;
}