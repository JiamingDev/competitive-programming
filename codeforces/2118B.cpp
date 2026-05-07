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
    cout << 2 * n - 1 << "\n";
    cout << "1 1 " << n << "\n";
    for (int i = 2; i <= n; i++)
      cout << i << " " << i << " " << n << "\n" << i << " " << 1 << " " << i - 1 << "\n";
  }
  return 0;
}