#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++)
      cin >> b[i];
    for (int i = 0; i < n; i++)
      cin >> c[i];
    ll k1 = 0;
    for (int i = 0; i < n; i++) {
      bool ok = 1;
      for (int j = 0; j < n; j++)
        if (a[(i + j) % n] >= b[j]) {
          ok = 0;
          break;
        }
      if (ok)
        k1++;
    }
    ll k2 = 0;
    for (int i = 0; i < n; i++) {
      bool ok = 1;
      for (int j = 0; j < n; j++)
        if (c[(i + j) % n] <= b[j]) {
          ok = 0;
          break;
        }
      if (ok)
        k2++;
    }
    cout << n * k1 * k2 << "\n";
  }
  return 0;
}