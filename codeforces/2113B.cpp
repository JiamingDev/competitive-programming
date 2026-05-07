#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, n) for (int i = 0; i < (n); i++)
signed main() {
  int T;
  cin >> T;
  while (T--) {
    int w, h, a, b, x1, y1, x2, y2;
    cin >> w >> h >> a >> b >> x1 >> y1 >> x2 >> y2;
    if (y1 != y2 && abs(y1 - y2) % b == 0 || x1 != x2 && abs(x1 - x2) % a == 0)
      cout << "yes\n";
    else
      cout << "no\n";
  }
  return 0;
}