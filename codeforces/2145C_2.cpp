#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int diff = 0;
    for (char c : s)
      if (c == 'a')
        diff++;
      else
        diff--;
    if (diff == 0) {
      cout << 0 << "\n";
      continue;
    }
    map<int, int> pre;
    pre[0] = -1;
    int cur = 0, ans = 1e9;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'a')
        cur++;
      else
        cur--;
      int need = cur - diff;
      if (pre.count(need))
        ans = min(ans, i - pre[need]);
      pre[cur] = i;
    }
    if (ans == n)
      cout << -1 << "\n";
    else
      cout << ans << "\n";
  }
  return 0;
}