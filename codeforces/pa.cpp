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
    int cnt = 0;
    for (int i = n - 1; i > 0; i--)
      if (a[i] > 0) {
        cnt++;
        a[i - 1] += a[i];
      }
    if (a[0] > 0)
      cnt++;
    cout << cnt << "\n";
  }
  return 0;
}