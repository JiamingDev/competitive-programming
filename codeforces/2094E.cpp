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
    vector<int> a(n), cnt(30);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      for (int j = 0; j < 30; j++)
        if (1 << j & a[i])
          cnt[j]++;
    }
    int maxv = 0;
    for (int i = 0; i < n; i++) {
      int sum = 0;
      for (int j = 0; j < 30; j++)
        if (1 << j & a[i])
          sum += (n - cnt[j]) * (1 << j);
        else
          sum += cnt[j] * (1 << j);
      maxv = max(maxv, sum);
    }
    cout << maxv << "\n";
  }
  return 0;
}