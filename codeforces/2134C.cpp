#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), need(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 1; i < n; i += 2) {
      need[i] += a[i - 1] - a[i];
      if (i + 1 < n)
        need[i] += a[i + 1];
    }
    int sum = 0;
    for (int i = 0; i < n; i += 2) {
      int s = 0;
      if (i > 0)
        s = max(s, need[i - 1]);
      if (i < n - 1)
        s = max(s, a[i] - a[i + 1]);
      sum += s;
      if (i < n - 1)
        need[i + 1] -= s;
    }
    cout << sum << "\n";
  }
  return 0;
}