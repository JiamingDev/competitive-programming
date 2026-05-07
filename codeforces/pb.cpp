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
    sort(a.begin(), a.end());
    if (a[0] > 0) {
      cout << n * a[n - 1] << "\n";
      continue;
    }
    if (n == 1) {
      cout << 1 << "\n";
      continue;
    }
    if (a[n - 1] == n - 1) {
      cout << n * n + (n - 1) * (n - 2) / 2 << "\n";
      continue;
    }
    int en = -1;
    int maxv = a[n - 1];
    a.erase(unique(a.begin(), a.end()), a.end());
    for (int i = 0; i < a.size(); i++)
      if (a[i] != i) {
        en = i;
        break;
      }
    if (en == -1)
      en = a.back() + 1;
    if (maxv == en - 1) {
      cout << n * (en - 1) + (en - 1) * (en - 2) / 2 + en + (n - en) * en << "\n";
      continue;
    }
    cout << en * (en + 1) / 2 + n * maxv + en * (n - en - 1) << "\n";
  }
  return 0;
}