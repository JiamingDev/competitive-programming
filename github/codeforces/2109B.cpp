#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, n) for (int i = 0; i < (n); i++)
int solve(int len) {
  int res = 0;
  while (len > 1) {
    len = (len + 1) / 2;
    res++;
  }
  return res;
}
signed main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    cout << min(solve(min(n - a + 1, a)) + solve(m), solve(min(m - b + 1, b)) + solve(n)) + 1 << "\n";
  }
  return 0;
}