#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
  int T;
  cin >> T;
  while (T--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    int cnt = sum / x;
    sum = 0;
    for (int i = 0; i < cnt; i++)
      sum += a[i];
    cout << sum << "\n";
    sum = 0;
    int l = 0, r = n - 1;
    while (l <= r) {
      if ((sum + a[l]) / x > sum / x) {
        cout << a[l] << " ";
        sum += a[l++];
      } else {
        cout << a[r] << " ";
        sum += a[r--];
      }
    }
    cout << "\n";
  }
  return 0;
}