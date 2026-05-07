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
    vector<int> a(n), b(n);
    forn(i, n) {
      cin >> a[i];
    }
    forn(i, n) {
      cin >> b[i];
    }
    vector<pair<int, int>> op;
    for (int i = 0; i < n - 1; i++)
      for (int j = 0; j < n - i - 1; j++) {
        if (a[j] > a[j + 1]) {
          swap(a[j], a[j + 1]);
          op.push_back({1, j + 1});
        }
        if (b[j] > b[j + 1]) {
          swap(b[j], b[j + 1]);
          op.push_back({2, j + 1});
        }
      }
    for (int i = 0; i < n; i++)
      if (a[i] > b[i])
        op.push_back({3, i + 1});
    cout << op.size() << "\n";
    for (auto [a, b] : op)
      cout << a << " " << b << "\n";
  }
  return 0;
}