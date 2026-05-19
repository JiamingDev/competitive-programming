#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (n); i++)
void solve() {
  int n;
  cin >> n;
  vector<vector<int>> v(n + 1);
  forn(i, n) {
    int t;
    cin >> t;
    v[t].push_back(i);
  }
  for (int i = 1; i <= n; i++)
    if (v[i].size() % i) {
      cout << -1 << "\n";
      return;
    }
  int val = 1;
  vector<int> ans(n);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < v[i].size(); j++) {
      ans[v[i][j]] = val;
      if ((j + 1) % i == 0)
        val++;
    }
  }
  for (int x : ans)
    cout << x << " ";
  cout << "\n";
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}