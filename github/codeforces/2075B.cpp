#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, n) for (int i = 0; i < (n); i++)
signed main() {
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int lef = a[0], righ = a.back();
    sort(a.begin(), a.end(), greater<int>());
    if (k == 1) {
      if (lef == a[1] || righ == a[1] || lef == a[0] || righ == a[0])
        cout << a[0] + a[1] << "\n";
      else
        cout << (max(a[0], a[1]) + max(lef, righ)) << "\n";
      continue;
    }
    int sum = 0;
    for (int i = 0; i < k + 1; i++)
      sum += a[i];
    cout << sum << "\n";
  }
  return 0;
}