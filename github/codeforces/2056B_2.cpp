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
    vector<string> s(n);
    for (int i = 0; i < n; i++)
      cin >> s[i];
    vector<int> v(n);
    iota(v.begin(), v.end(), 0);
    sort(v.begin(), v.end(), [&](int i, int j) {
      if (s[i][j] == '1')
        return i < j;
      else
        return i > j;
    });
    for (int x : v)
      cout << x + 1 << " ";
    cout << "\n";
  }
  return 0;
}