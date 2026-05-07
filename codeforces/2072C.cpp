#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, n) for (int i = 0; i < (n); i++)
signed main() {
  int T;
  cin >> T;
  while (T--) {
    int n, x;
    cin >> n >> x;
    if (n == 1) {
      cout << x << "\n";
      continue;
    }
    if (!(x & 1)) {
      cout << "0 ";
      for (int i = 0; i < n - 1; i++)
        cout << x << " ";
      cout << "\n";
    } else {
      int t;
      for (int i = 0;; i++)
        if (!(1 << i & x)) {
          t = i;
          break;
        }
      if (n > 1 << t) {
        for (int i = 0; i < 1 << t; i++)
          cout << i << " ";
        for (int i = 0; i < n - (1 << t); i++)
          cout << x << " ";
        cout << "\n";
      } else if (__builtin_clz(n - 1) == __builtin_clz(x))
        for (int i = 0; i < n; i++)
          cout << i << " \n"[i == n - 1];
      else {
        for (int i = 0; i < n - 1; i++)
          cout << i << " ";
        cout << x << "\n";
      }
    }
  }
  return 0;
}