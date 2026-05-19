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
    for (int &x : a)
      cin >> x;
    int best_diff = 0, l = 0, r = 0;
    for (int i = 0; i < n; i++) {
      int cnt = 0, cnt2 = 0;
      for (int j = i + 1; j < n; j++) {
        if (a[j] > a[i])
          cnt2++;
        else if (a[j] < a[i])
          cnt++;
        if (cnt - cnt2 > best_diff) {
          best_diff = cnt - cnt2;
          l = i, r = j;
        }
      }
    }
    cout << l + 1 << " " << r + 1 << "\n";
  }
  return 0;
}