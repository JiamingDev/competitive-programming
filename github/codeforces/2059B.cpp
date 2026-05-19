#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, n) for (int i = 0; i < (n); i++)
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  if (k == n) {
    for (int i = 0; 2 * i + 1 < n; i++)
      if (a[i * 2 + 1] != i + 1) {
        cout << i + 1 << "\n";
        return;
      }
    cout << n / 2 + 1 << "\n";
    return;
  }
  for (int i = 1; i < n - (k - 2); i++)
    if (a[i] != 1) {
      cout << 1 << "\n";
      return;
    }
  cout << "2\n";
}
signed main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}