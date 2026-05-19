#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, n) for (int i = 0; i < (n); i++)
signed main() {
  int T;
  cin >> T;
  while (T--) {
    int n, x, res = 0;
    cin >> n >> x;
    vector<int> ans;
    for (int i = 0; i < n; i++)
      if ((i & ~x) == 0) {
        ans.push_back(i);
        res |= i;
      } else
        break;
    if (ans.size() == n && res != x)
      ans[n - 1] = x;
    for (int t : ans)
      cout << t << " ";
    for (int i = 0; i < n - ans.size(); i++)
      cout << x << " ";
  }
  return 0;
}