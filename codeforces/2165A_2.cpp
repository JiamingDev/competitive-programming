#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
signed main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    int maxv = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      maxv = max(maxv, a[i]);
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
      sum += max(a[i], a[(i + 1) % n]);
    cout << sum - maxv << "\n";
  }
  return 0;
}