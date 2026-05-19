#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, n) for (int i = 0; i < (n); i++)
signed main() {
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    forn(i, n) {
      int t;
      cin >> t;
      cout << t + t % (k + 1) * k << " ";
    }
    cout << "\n";
  }
  return 0;
}