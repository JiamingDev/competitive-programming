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
    vector<int> b(n);
    for (int i = 0; i < n; i++)
      cin >> b[i];
    int x = 1;
    forn(i, n - 1) {
      x = lcm(x, b[i] / gcd(b[i], b[i + 1]));
    }
    cout << x << "\n";
  }
  return 0;
}