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
    vector<pair<int, int>> deg(n + 1);
    for (int i = 1; i <= n; i++)
      deg[i] = {0, i};
    for (int i = 1; i <= n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < n; j++)
        if (s[j] == '1') {
          deg[max(j + 1, i)].first++;
        } else {
          deg[min(j + 1, i)].first++;
        }
    }
    sort(deg.begin() + 1, deg.end());
    for (int i = 1; i <= n; i++)
      cout << deg[i].second << " ";
    cout << "\n";
  }
  return 0;
}