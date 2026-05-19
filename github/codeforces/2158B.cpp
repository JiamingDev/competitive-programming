#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < 2 * n; i++) {
      int t;
      cin >> t;
      cnt[t]++;
    }
    int x = 0, y = 0;
    int res = 0;
    for (auto [k, v] : cnt)
      if (v & 1)
        y++;
      else if ((v / 2) & 1)
        res += 2;
      else
        x++;
    if (x & 1 && y == 0)
      cout << res + 2 * (x - 1) << "\n";
    else
      cout << res + 2 * x + y << "\n";
  }
  return 0;
}