#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, n) for (int i = 0; i < (n); i++)
signed main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int sum = 0;
      for (int j = 0; j < m; j++) {
        int t;
        cin >> t;
        sum += t;
        ans += sum;
      }
      s.push_back({sum});
    }
    sort(s.begin(), s.end());
    for (int i = 0; i < n; i++)
      ans += s[i] * i * m;
    cout << ans << "\n";
  }
  return 0;
}