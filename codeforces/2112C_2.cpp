#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
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
    int sum = 0;
    for (int z = 0; z < a.size(); z++) {
      int l = 0, r = z - 1;
      while (l < r) {
        if (a[l] + a[r] > max(a[z], a[n - 1] - a[z])) {
          sum += r - l;
          r--;
        } else
          l++;
      }
    }
    cout << sum << "\n";
  }
  return 0;
}